#include "texts.hpp"
bool SDLCommonFunc::CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2)
{
    int left_a = object1.x;
  int right_a = object1.x + object1.w;
  int top_a = object1.y;
  int bottom_a = object1.y + object1.h;

  int left_b = object2.x;
  int right_b = object2.x + object2.w;
  int top_b = object2.y;
  int bottom_b = object2.y + object2.h;

  // Case 1: size object 1 > size object 2
  if (left_a > left_b && left_a < right_b)
  {
    if (top_a > top_b && top_a < bottom_b)
    {
      return true;
    }
  }

  if (left_a > left_b && left_a < right_b)
  {
    if (bottom_a > top_b && bottom_a < bottom_b)
    {
      return true;
    }
  }

  if (right_a > left_b && right_a < right_b)
  {
    if (top_a > top_b && top_a < bottom_b)
    {
      return true;
    }
  }

  if (right_a > left_b && right_a < right_b)
  {
    if (bottom_a > top_b && bottom_a < bottom_b)
    {
      return true;
    }
  }

  // Case 2: size object 1 < size object 2
  if (left_b > left_a && left_b < right_a)
  {
    if (top_b > top_a && top_b < bottom_a)
    {
      return true;
    }
  }

  if (left_b > left_a && left_b < right_a)
  {
    if (bottom_b > top_a && bottom_b < bottom_a)
    {
      return true;
    }
  }

  if (right_b > left_a && right_b < right_a)
  {
    if (top_b > top_a && top_b < bottom_a)
    {
      return true;
    }
  }

  if (right_b > left_a && right_b < right_a)
  {
    if (bottom_b > top_a && bottom_b < bottom_a)
    {
      return true;
    }
  }

   // Case 3: size object 1 = size object 2
  if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
  {
    return true;
  }

  return false;
}

bool SDLCommonFunc::CheckFocusWithRect(int x, int y, SDL_Rect& buttonrect)
{
    if(x >= buttonrect.x && x <= buttonrect.x + buttonrect.w && y >= buttonrect.y && y <= buttonrect.y + buttonrect.h)
    {
        return true;
    }else
    {
        return false;
    }
}

int SDLCommonFunc::ShowMenu(SDL_Renderer* des, TTF_Font* menufont)
{
    Sint32 mxpos, mypos;
    const int options = 2;
    SDL_Rect pos_arr[options];
    pos_arr[0].x = 270;
    pos_arr[0].y = 400;

    pos_arr[1].x = 270;
    pos_arr[1].y = 450;

    Texts options_text[options+1];

    options_text[0].SetText("Play");
    options_text[0].SetColor(Texts::BLACK);
    options_text[0].LoadFromRenderedText(menufont,des);
    pos_arr[0].w = options_text[0].GetWidth();
    pos_arr[0].h = options_text[0].GetHeight();
    options_text[0].RenderText(des,pos_arr[0].x,pos_arr[0].y,NULL,NULL,SDL_FLIP_NONE);

    options_text[1].SetText("Quit");
    options_text[1].SetColor(Texts::BLACK);
    options_text[1].LoadFromRenderedText(menufont,des);
    pos_arr[1].w = options_text[1].GetWidth();
    pos_arr[1].h = options_text[1].GetHeight();
    options_text[1].RenderText(des,pos_arr[1].x,pos_arr[1].y,NULL,NULL,SDL_FLIP_NONE);

    SDL_Event mouseevent;
    while(true)
    {
        SDL_RenderPresent(des);
        while(SDL_PollEvent(&mouseevent))
        {
        switch(mouseevent.type)
        {
        case SDL_QUIT:
            return 1;
            break;
            case SDL_MOUSEBUTTONDOWN:
            mxpos = mouseevent.motion.x;
            mypos = mouseevent.motion.y;
            for(int i = 0; i < options; i++)
            {
                if(CheckFocusWithRect(mxpos,mypos,pos_arr[i]))
                {
                    return i;
                }
            }
            break;
            default:
            break;
        }
        }
    }
    return 1;
}

int SDLCommonFunc::ShowGameOverScreen(SDL_Renderer* des, TTF_Font* gameoverfont, Uint32 &playerrecord)
{
    Sint32 mxpos, mypos;
    const int options = 2;
    SDL_Rect pos_arr[options];
    pos_arr[0].x = 200;
    pos_arr[0].y = 400;

    pos_arr[1].x = 200;
    pos_arr[1].y = 450;

    Texts options_text[options+1];
    Texts display_record[2];

    display_record[0].SetText("Game Over");
    display_record[0].SetColor(Texts::WHITE);
    display_record[0].LoadFromRenderedText(gameoverfont,des);
    display_record[0].RenderText(des,200,300,NULL,NULL,SDL_FLIP_NONE);

    display_record[1].SetText("Total Survival Time: " + std::to_string(playerrecord));
    display_record[1].SetColor(Texts::WHITE);
    display_record[1].LoadFromRenderedText(gameoverfont,des);
    display_record[1].RenderText(des,200,350,NULL,NULL,SDL_FLIP_NONE);


    options_text[0].SetText("Restart");
    options_text[0].SetColor(Texts::WHITE);
    options_text[0].LoadFromRenderedText(gameoverfont,des);
    pos_arr[0].w = options_text[0].GetWidth();
    pos_arr[0].h = options_text[0].GetHeight();
    options_text[0].RenderText(des,pos_arr[0].x,pos_arr[0].y,NULL,NULL,SDL_FLIP_NONE);

    options_text[1].SetText("Menu");
    options_text[1].SetColor(Texts::WHITE);
    options_text[1].LoadFromRenderedText(gameoverfont,des);
    pos_arr[1].w = options_text[1].GetWidth();
    pos_arr[1].h = options_text[1].GetHeight();
    options_text[1].RenderText(des,pos_arr[1].x,pos_arr[1].y,NULL,NULL,SDL_FLIP_NONE);

    SDL_Event mouseevent;
    while(true)
    {
        SDL_RenderPresent(des);
        while(SDL_PollEvent(&mouseevent))
        {
        switch(mouseevent.type)
        {
        case SDL_QUIT:
            return 2;
            break;
            case SDL_MOUSEBUTTONDOWN:
            mxpos = mouseevent.motion.x;
            mypos = mouseevent.motion.y;
            for(int i = 0; i < options; i++)
            {
                if(CheckFocusWithRect(mxpos,mypos,pos_arr[i]))
                {
                    return i;
                }
            }
            break;
            default:
            break;
        }
        }
    }
    return 2;
}
