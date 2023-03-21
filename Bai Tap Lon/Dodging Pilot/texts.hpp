#ifndef TEXTS_HPP_INCLUDED
#define TEXTS_HPP_INCLUDED
#include "commonfunctions.hpp"

class Texts
{
public:
    Texts();
    ~Texts();
    enum TextColor
    {
        RED = 0,
        WHITE = 1,
        BLACK = 2,
    };
    bool LoadFromRenderedText(TTF_Font* font, SDL_Renderer* ren);
    void FreeTex();
    void SetColor(Uint8 red, Uint8 green, Uint8 blue);
    void SetColor(int chosencolor);
    void RenderText(SDL_Renderer* dest, int x_pos, int y_pos, SDL_Rect* clip = NULL, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
    int GetWidth() const {return width;}
    int GetHeight() const {return height;}
    void SetText(const std::string& val_) {text_ = val_;}
    std::string GetText() const {return text_;}
private:
    std::string text_;
    SDL_Color tex_color;
    SDL_Texture* tex_texture;
    int width;
    int height;
};

#endif // TEXTS_HPP_INCLUDED
