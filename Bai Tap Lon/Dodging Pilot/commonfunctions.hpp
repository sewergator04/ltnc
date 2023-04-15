#ifndef COMMONFUNCTIONS_HPP_INCLUDED
#define COMMONFUNCTIONS_HPP_INCLUDED

#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>


const int ScreenWidth = 600;
const int ScreenHeight = 1000;
const int ScreenBPP = 32;
const int BulletsNum = 8;
const int FPS = 60;
const int FrameTime = 1000/FPS;
namespace SDLCommonFunc
{
    bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);
    int ShowMenu(SDL_Renderer* des, TTF_Font* menufont);
    int ShowGameOverScreen(SDL_Renderer* des, TTF_Font* gameoverfont, Uint32 &playerrecord);
    bool CheckFocusWithRect(int x, int y, SDL_Rect& buttonrect);
}


#endif // COMMONFUNCTIONS_HPP_INCLUDED
