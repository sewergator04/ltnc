#ifndef HIGHSCORESAVER_HPP_INCLUDED
#define HIGHSCORESAVER_HPP_INCLUDED
#include "commonfunctions.hpp"
class HighScore
{
public:
    HighScore();
    ~HighScore();
    Uint32 GetHighScore() const {return Record;};
    void SaveNewHighScore(Uint32 newhighscore);
    void ReadHighScore();
    bool CheckHighScore(Uint32 currentscore);
private:
    Uint32 Record;
    std::string textpath_ = "highscore.txt";
};

#endif // HIGHSCORESAVER_HPP_INCLUDED
