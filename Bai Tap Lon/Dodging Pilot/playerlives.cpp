#include "playerlives.hpp"
PlayerLives::PlayerLives()
{

}

PlayerLives::~PlayerLives()
{

}

void PlayerLives::AddPos(const int& xpos)
{
    text_pos_.push_back(xpos);
}

void PlayerLives::LiveRender(SDL_Renderer* realren)
{
    if(livesnum == text_pos_.size())
    {
        for(int i = 0; i < text_pos_.size(); i++)
        {
            rect_.x = text_pos_.at(i);
            Render(realren,NULL);
        }
    }
}

void PlayerLives::Init(SDL_Renderer* actualren)
{
    LoadImg("assets//lives.png",actualren);
    livesnum = 3;
    if(text_pos_.size() > 0)
    {
        text_pos_.clear();
    }
    AddPos(0);
    AddPos(64);
    AddPos(64*2);
}

void PlayerLives::Decrease()
{
    livesnum--;
    text_pos_.pop_back();
}
