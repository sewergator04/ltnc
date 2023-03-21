#include "commonfunctions.hpp"
#include "baseobject.hpp"
#include "mainobject.hpp"
#include "bullets.hpp"
#include "playerlives.hpp"
#include "texts.hpp"

BaseObject background;
Mix_Music* backgroundmusic = NULL;
Mix_Chunk* damagemusic = NULL;
MainObject plane;
Bullet* straightbuls = new Bullet[BulletsNum];
PlayerLives hearts;
TTF_Font* font_cooldown = NULL;
Texts cooldowntimer;
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
            backgroundmusic = Mix_LoadMUS("soundtrack//maxwell.mp3");
            damagemusic = Mix_LoadWAV("soundtrack//PlaneHit.wav");
            if(backgroundmusic == NULL && damagemusic == NULL)
            {
                success = false;
            }
        }
        if(TTF_Init() == -1)
        {
            success = false;
        }else
        {
            font_cooldown = TTF_OpenFont("font//DTM-Sans.ttf",80);
            if(font_cooldown == NULL)
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
    Mix_FreeChunk(damagemusic);
    Mix_CloseAudio();
    cooldowntimer.FreeTex();
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
    cooldowntimer.SetColor(Texts::WHITE);

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
                    cooldowntimer.SetText("3");
                    cooldowntimer.LoadFromRenderedText(font_cooldown,renderer);
                }else if(invincible == 6666)
                {
                    cooldowntimer.SetText("2");
                    cooldowntimer.LoadFromRenderedText(font_cooldown,renderer);
                    //cooldowntimer.RenderText(renderer,275,0);
                }else if(invincible == 3333)
                {
                    cooldowntimer.SetText("1");
                    cooldowntimer.LoadFromRenderedText(font_cooldown,renderer);
                    //cooldowntimer.RenderText(renderer,275,0);
                }
                invincible--;
                continue;
            }
            bool isCol = SDLCommonFunc::CheckCollision(plane.GetRect(), straightbul->GetRect());
            if(isCol)
            {
                Mix_PlayChannel(-1,damagemusic,0);
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
        if(invincible == 0)
        {
            cooldowntimer.SetText("0");
            cooldowntimer.LoadFromRenderedText(font_cooldown,renderer);
        }
        cooldowntimer.RenderText(renderer,275,0);
        SDL_RenderPresent(renderer);
        SDL_Delay(1);
    }
    Close();
    return 0;
}
