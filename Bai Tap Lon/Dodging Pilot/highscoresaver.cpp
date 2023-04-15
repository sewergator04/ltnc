#include "highscoresaver.hpp"

HighScore::HighScore()
{
    ;
}

HighScore::~HighScore()
{
    ;
}

void HighScore::ReadHighScore()
{
    std::ifstream read(textpath_.c_str());
    Uint32 score;
    read >> score;
    Record = score;
    read.close();
}

bool HighScore::CheckHighScore(Uint32 currentscore)
{
    if(Record < currentscore)
    {
        return true;
    }else
    {
        return false;
    }
}

void HighScore::SaveNewHighScore(Uint32 newhighscore)
{
    std::ofstream write(textpath_.c_str());
    write << newhighscore;
    write.close();
    Record = newhighscore;
}
