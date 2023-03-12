#include "mainobject.hpp"
MainObject::MainObject()
{
    rect_.x = 275;
    rect_.y = 936/2;
    rect_.w = WIDTH_MAIN_OBJECT;
    rect_.h = HEIGHT_MAIN_OBJECT;
    x_val = 0;
    y_val = 0;
}

MainObject::~MainObject()
{
    ;
}

void MainObject::HandleInputAction(SDL_Event ev)
{
    if(ev.type == SDL_KEYDOWN)
    {
        switch(ev.key.keysym.sym)
        {
        case SDLK_UP:
            y_val = -1;
            break;
        case SDLK_DOWN:
            y_val = 1;
            break;
        case SDLK_LEFT:
            x_val = -1;
            break;
        case SDLK_RIGHT:
            x_val = 1;
            break;
        default:
            break;
        }

    }
    else if(ev.type == SDL_KEYUP)
    {
        switch(ev.key.keysym.sym)
        {
        case SDLK_UP:
            if(y_val < 0)
            {
                y_val = 0;
            }
            break;
        case SDLK_DOWN:
            if(y_val > 0)
            {
                y_val = 0;
            }
            break;
        case SDLK_LEFT:
            if(x_val < 0)
            {
                x_val = 0;
            }
            break;
        case SDLK_RIGHT:
            if(x_val > 0)
            {
                x_val = 0;
            }
            break;
        default:
            break;
        }
    }
}

void MainObject::HandleMove()
{
    rect_.x += x_val;
    //std::cout << rect_.x << " ";
    if(rect_.x < 0 || rect_.x + WIDTH_MAIN_OBJECT > ScreenWidth)
    {
        rect_.x -= x_val;
    }
    rect_.y += y_val;
    //std::cout << rect_.y << std::endl;
    if(rect_.y < 0 || rect_.y + HEIGHT_MAIN_OBJECT > ScreenHeight)
    {
        rect_.y -= y_val;
    }

}
