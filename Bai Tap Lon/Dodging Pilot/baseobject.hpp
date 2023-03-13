#ifndef BASEOBJECT_HPP_INCLUDED
#define BASEOBJECT_HPP_INCLUDED

#include "commonfunctions.hpp"

class BaseObject
{
public:
    BaseObject();
    ~BaseObject();
    void SetRect(const float& x, const float& y) {rect_.x = x; rect_.y = y;}
    SDL_Rect GetRect() const {return rect_;}
    SDL_Texture* GetObject() const {return p_object_;}
    bool LoadImg(std::string path, SDL_Renderer* ren);
    void Render(SDL_Renderer* dest, const SDL_Rect* clip = NULL);
    void Free();
protected:
    SDL_Texture* p_object_;
    SDL_Rect rect_;
};

#endif // BASEOBJECT_HPP_INCLUDED
