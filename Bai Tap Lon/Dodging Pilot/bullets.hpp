#ifndef BULLETS_HPP_INCLUDED
#define BULLETS_HPP_INCLUDED

#include "baseobject.hpp"

#define WIDTH_BULLET 64
#define HEIGHT_BULLET 64
class Bullet : public BaseObject
{
public:
    Bullet();
    ~Bullet();
    void HandleMove();
    void HandleInputAction(SDL_Event events);
    void set_x_val(const int &val) {bul_x_val = val;}
    void set_y_val(const int &val) {bul_y_val = val;}
    int get_x_val() const {return bul_x_val;}
    int get_y_val() const {return bul_y_val;}
private:
    float bul_x_val;
    float bul_y_val;
};
#endif // BULLETS_HPP_INCLUDED
