#ifndef MAINOBJECT_HPP_INCLUDED
#define MAINOBJECT_HPP_INCLUDED

#include "baseobject.hpp"

#define WIDTH_MAIN_OBJECT 64
#define HEIGHT_MAIN_OBJECT 64
class MainObject : public BaseObject
{
public:
    MainObject();
    ~MainObject();
    void HandleInputAction(SDL_Event ev);
    void HandleMove();
private:
    float x_val;
    float y_val;
};
#endif // MAINOBJECT_HPP_INCLUDED
