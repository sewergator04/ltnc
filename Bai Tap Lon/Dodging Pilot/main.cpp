#include "commonfunctions.hpp"
#include "baseobject.hpp"
#include "mainobject.hpp"
#include "bullets.hpp"
#include "playerlives.hpp"

BaseObject background;
Mix_Music* backgroundmusic = NULL;
MainObject plane;
Bullet* straightbuls = new Bullet[BulletsNum];
PlayerLives hearts;
int invincible = 0;

bool InitData()
{
    bool success = true;
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if(ret < 0)
    {
        success = false;
    }
    int mixerinit = SDL_Init(SDL_INIT_AUDIO);
    if(mixerinit < 0)
    {
        success = false;
    }else
    {
        int audioinit = Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
        if(audioinit < 0)
        {
            success = false;
        }else
        {
            backgroundmusic = Mix_LoadMUS("maxwell.mp3");
            if(backgroundmusic == NULL)
            {
                success = false;
            }
        }
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    window = SDL_CreateWindow("SDL2 Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN);
    if(window == NULL)
    {
        success = false;
    }else
    {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if(renderer == NULL)
        {
            success = false;
        }else
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            int imgflags = IMG_INIT_PNG;
            if(!(IMG_Init(imgflags) && imgflags))
            {
                success = false;
            }
        }
    }
    return success;
}

bool loadbackground()
{
    bool ret = background.LoadImg("assets//bluemoon.png",renderer);
    if(ret == false)
    {
        return false;
    }
    return true;
}

bool loadPlane()
{
    bool player = plane.LoadImg("assets//plane.png",renderer);
    if(player == false)
    {
        return false;
    }
    return true;
}

void Close()
{
    background.Free();
    plane.Free();
    Mix_FreeMusic(backgroundmusic);
    Mix_CloseAudio();
    for(int i = 0; i < BulletsNum; i++)
    {
        Bullet* freebul = (straightbuls+i);
        freebul->Free();
    }
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(window);
    window = NULL;
    IMG_Quit();
    SDL_Quit();
}

int main(int agrc, char* argv[])
{
    if(InitData() == false)
    {
        return -1;
    }
    if(loadbackground() == false)
    {
        return -1;
    }
    if(loadPlane() == false)
    {
        return -1;
    }
    for(int i = 0; i < BulletsNum; i++)
    {
        Bullet* straightbul = (straightbuls+i);
        bool bullettext = straightbul->LoadImg("assets//bullet.png",renderer);
        if(bullettext == false)
        {
            return -1;
        }
        int randstartx = rand()%536;
        straightbul->SetRect(randstartx,-64-400*i);
        straightbul->set_y_val(1);
    }
    hearts.Init(renderer);
    unsigned int deaths = 0;
    bool is_quit = false;
    Mix_PlayMusic(backgroundmusic, -1);

    while(!is_quit)
    {
        while(SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT)
            {
                is_quit = true;
                break;
            }
            plane.HandleInputAction(e);
        }
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        background.Render(renderer, NULL);
        hearts.LiveRender(renderer);
        plane.HandleMove();
        plane.Render(renderer,NULL);
        for(int j = 0; j < BulletsNum; j++)
        {
            Bullet* straightbul = (straightbuls+j);
            straightbul->HandleMove();
            straightbul->Render(renderer,NULL);
            if(invincible > 0)
            {
                if(invincible == 9999)
                {
                    std::cout << 3 << std::endl;
                }else if(invincible == 6666)
                {
                    std::cout << 2 << std::endl;
                }else if(invincible == 3333)
                {
                    std::cout << 1 << std::endl;
                }
                invincible--;
                continue;
            }
            bool isCol = SDLCommonFunc::CheckCollision(plane.GetRect(), straightbul->GetRect());
            if(isCol)
            {

                deaths++;
                if(deaths <= 2)
                {
                    hearts.Decrease();
                    hearts.LiveRender(renderer);
                    invincible = 9999;
                }else
                {
                    std::cout << "All lives lost! - Game Over" << std::endl;
                    Close();
                    return 0;
                }
            }
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(1);
    }
    Close();
    return 0;
}
