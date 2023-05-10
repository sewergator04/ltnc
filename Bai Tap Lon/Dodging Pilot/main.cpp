#include "commonfunctions.hpp"
#include "baseobject.hpp"
#include "mainobject.hpp"
#include "bullets.hpp"
#include "playerlives.hpp"
#include "texts.hpp"
#include "highscoresaver.hpp"

BaseObject background,menubackground,gameoverbackground;
Mix_Music* backgroundmusic = NULL;
Mix_Chunk* damagemusic = NULL;
MainObject plane;
Bullet* straightbuls = new Bullet[BulletsNum];
PlayerLives hearts;
TTF_Font* font_cooldown = NULL;
TTF_Font* font_survivaltime = NULL;
Texts cooldowntimer,survivetime;
HighScore highscoresystem;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Event e;


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
            font_survivaltime = TTF_OpenFont("font//DTM-Sans.ttf",20);
            if(font_cooldown == NULL)
            {
                success = false;
            }
        }
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    window = SDL_CreateWindow("Dodging Pilot v2.1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN);
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

bool loadmenubackground()
{
    bool results = menubackground.LoadImg("assets//menubackground.jpg",renderer);
    if(results == false)
    {
        return false;
    }
    return true;
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


bool loadgameoverbackground()
{
    bool results = gameoverbackground.LoadImg("assets//gameover.jpg",renderer);
    if(results == false)
    {
        return false;
    }
    return true;
}

void Close()
{
    background.Free();
    menubackground.Free();
    gameoverbackground.Free();
    plane.Free();
    Mix_FreeMusic(backgroundmusic);
    Mix_FreeChunk(damagemusic);
    Mix_CloseAudio();
    cooldowntimer.FreeTex();
    survivetime.FreeTex();
    for(int i = 0; i < BulletsNum; i++)
    {
        Bullet* freebul = (straightbuls+i);
        freebul->Free();
    }
    delete []straightbuls;
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
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
    if(loadmenubackground() == false)
    {
        return -1;
    }
    if(loadgameoverbackground() == false)
    {
        return -1;
    }
    //Variables
    Uint32 startTime;
    Uint32 elapsedTime = 0;
    Uint32 lastUpdateTime = 0;
    Uint32 savedTime;
    unsigned int deaths = 0;
    bool is_quit = false;
    bool start_counting = false;
    bool startcooldown = false;
    Uint32 finalTime;
    int cooldownremains;
    Uint32 markedcooldown;
    int invincible = 0;

    Mix_PlayMusic(backgroundmusic, -1);

    GameMenu:
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    menubackground.Render(renderer,NULL);
    SDL_RenderPresent(renderer);
    Texts displayhighonmenu;
    highscoresystem.ReadHighScore();
    std::string texttodisplay = "High Score: " + std::to_string(highscoresystem.GetHighScore());
    displayhighonmenu.SetText(texttodisplay);
    displayhighonmenu.SetColor(Texts::BLACK);
    displayhighonmenu.LoadFromRenderedText(font_survivaltime,renderer);
    displayhighonmenu.RenderText(renderer,230,350,NULL,NULL,SDL_FLIP_NONE);
    int GUI = SDLCommonFunc::ShowMenu(renderer,font_survivaltime);
    if(GUI == 1)
    {
        is_quit = true;
    }else if(GUI == 0)
    {
        startTime = SDL_GetTicks();
        start_counting = true;
    }

    NewRound:
    highscoresystem.ReadHighScore();
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
    cooldowntimer.SetColor(Texts::WHITE);
    plane.SetRect(275,468);


    while(!is_quit)
    {
        Uint32 FPSstarttime = SDL_GetTicks();
        while(SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT)
            {
                is_quit = true;
                break;
            }
            plane.HandleInputAction(e);
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        background.Render(renderer, NULL);
        hearts.LiveRender(renderer);
        plane.HandleMove();
        plane.Render(renderer,NULL);
        if(start_counting)
        {
            Uint32 currentTime = SDL_GetTicks() - startTime;
            Uint32 deltaTime = currentTime - lastUpdateTime;
            lastUpdateTime = currentTime;
            elapsedTime += deltaTime;
            finalTime = elapsedTime/1000;
            savedTime = finalTime;
            std::string SurviveTimeStr = "Survive Time: " + std::to_string(finalTime);
            survivetime.SetText(SurviveTimeStr);
            survivetime.LoadFromRenderedText(font_survivaltime,renderer);
        }
        if(startcooldown)
        {
            Uint32 currentTimeforcooldown = SDL_GetTicks();
            cooldownremains = invincible - (currentTimeforcooldown-markedcooldown);
        }
        for(int j = 0; j < BulletsNum; j++)
        {
            Bullet* straightbul = (straightbuls+j);
            straightbul->HandleMove();
            straightbul->Render(renderer,NULL);
            if(cooldownremains > 0)
            {
                if(cooldownremains > 2000 && cooldownremains <= 3000)
                {
                    cooldowntimer.SetText("3");
                    cooldowntimer.LoadFromRenderedText(font_cooldown,renderer);
                }else if(cooldownremains > 1000 && cooldownremains <= 2000)
                {
                    cooldowntimer.SetText("2");
                    cooldowntimer.LoadFromRenderedText(font_cooldown,renderer);
                }else if(cooldownremains <= 1000)
                {
                    cooldowntimer.SetText("1");
                    cooldowntimer.LoadFromRenderedText(font_cooldown,renderer);
                }
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
                    invincible = 3000;
                    markedcooldown = SDL_GetTicks();
                    startcooldown = true;
                }else
                {
                    start_counting = false;
                    SDL_RenderClear(renderer);
                    gameoverbackground.Render(renderer,NULL);
                    SDL_RenderPresent(renderer);
                    if(highscoresystem.GetHighScore() < finalTime)
                    {
                        highscoresystem.SaveNewHighScore(finalTime);
                        Texts displaynotif;
                        displaynotif.SetText("New High Score!");
                        displaynotif.SetColor(Texts::WHITE);
                        displaynotif.LoadFromRenderedText(font_survivaltime,renderer);
                        displaynotif.RenderText(renderer,200,250,NULL,NULL,SDL_FLIP_NONE);
                    }
                    int GameOver = SDLCommonFunc::ShowGameOverScreen(renderer,font_survivaltime,savedTime);
                    if(GameOver == 2)
                    {
                        is_quit = true;
                        Close();
                        return 0;
                    }else if(GameOver == 1)
                    {
                        SDL_RenderClear(renderer);
                        deaths = 0;
                        hearts.Init(renderer);
                        goto GameMenu;
                    }else
                    {
                        deaths = 0;
                        startTime = SDL_GetTicks();
                        start_counting = true;
                        goto NewRound;
                    }
                }
            }
        }
        survivetime.RenderText(renderer,230,80);
        cooldowntimer.RenderText(renderer,275,0);
        SDL_RenderPresent(renderer);
        Uint32 frame_duration = SDL_GetTicks() - FPSstarttime;
        if(frame_duration < FrameTime)
        {
            SDL_Delay(FrameTime - frame_duration);
        }
    }
    Close();
    return 0;
}
