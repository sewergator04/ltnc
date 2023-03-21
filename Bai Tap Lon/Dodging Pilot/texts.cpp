#include "texts.hpp"
Texts::Texts()
{
    tex_color.r = 255;
    tex_color.g = 255;
    tex_color.b = 255;
    tex_texture = NULL;
}

Texts::~Texts()
{

}

bool Texts::LoadFromRenderedText(TTF_Font* font,SDL_Renderer* ren)
{
    SDL_Surface* text_surface = TTF_RenderText_Solid(font, text_.c_str(), tex_color);
    if(text_surface)
    {
        tex_texture = SDL_CreateTextureFromSurface(ren,text_surface);
        width = text_surface->w;
        height = text_surface->h;
        SDL_FreeSurface(text_surface);

    }
    return tex_texture != NULL;
}

void Texts::FreeTex()
{
    if(tex_texture != NULL)
    {
        SDL_DestroyTexture(tex_texture);
        tex_texture = NULL;
    }
}

void Texts::SetColor(Uint8 red, Uint8 green, Uint8 blue)
{
    tex_color.r = red;
    tex_color.g = green;
    tex_color.b = blue;
}

void Texts::SetColor(int chosencolor)
{
    if(chosencolor == RED)
    {
        SDL_Color color = {255, 0 , 0};
        tex_color = color;
    }else if(chosencolor == WHITE)
    {
        SDL_Color color = {255, 255 , 255};
        tex_color = color;
    }else if(chosencolor == BLACK)
    {
        SDL_Color color = {0, 0 , 0};
        tex_color = color;
    }
}

void Texts::RenderText(SDL_Renderer* dest, int x_pos, int y_pos, SDL_Rect* clip /*= NULL*/, SDL_Point* center /*= NULL*/, SDL_RendererFlip flip /*= SDL_FLIP_NONE*/)
{
    SDL_Rect renderQuad = {x_pos,y_pos,width,height};
    SDL_RenderCopyEx(dest,tex_texture,clip, &renderQuad,0.0,center,flip);
}
