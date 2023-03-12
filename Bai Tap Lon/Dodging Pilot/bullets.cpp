#include "bullets.hpp"
Bullet::Bullet()
{
    rect_.x = 0;
    rect_.y = 0;
    rect_.w = WIDTH_BULLET;
    rect_.h = HEIGHT_BULLET;
    bul_x_val = 0;
    bul_y_val = 1;
}

Bullet::~Bullet()
{
    ;
}

void Bullet::HandleMove()
{
    rect_.y += bul_y_val;
    if(rect_.y > ScreenHeight)
    {
        rect_.y = -64;
        int rand_x = rand()%536;
        if(rand_x > ScreenWidth)
        {
            rand_x = ScreenWidth;
        }
        rect_.x = rand_x;
    }
}

void Bullet::HandleInputAction(SDL_Event events)
{
    ;
}
