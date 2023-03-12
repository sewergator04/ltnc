#ifndef COMMONFUNCTIONS_HPP_INCLUDED
#define COMMONFUNCTIONS_HPP_INCLUDED

#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;
static SDL_Event e;

const int ScreenWidth = 600;
const int ScreenHeight = 1000;
const int ScreenBPP = 32;
const int BulletsNum = 8;

namespace SDLCommonFunc
{
    bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);
}


#endif // COMMONFUNCTIONS_HPP_INCLUDED
