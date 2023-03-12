#ifndef PLAYERLIVES_HPP_INCLUDED
#define PLAYERLIVES_HPP_INCLUDED

#include "baseobject.hpp"

class PlayerLives : public BaseObject
{
public:
    PlayerLives();
    ~PlayerLives();
    void SetNumer(const int& num) {livesnum = num;}
    void AddPos(const int& xpos);
    void LiveRender(SDL_Renderer* realren);
    void Init(SDL_Renderer* actualren);
    void Decrease();
private:
    int livesnum;
    std::vector<int> text_pos_;
};

#endif // PLAYERLIVES_HPP_INCLUDED
