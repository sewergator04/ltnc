#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;

vector<string>initvocab(string word)
{
    vector<string> vocabulary;
    while(word != ".")
    {
        cin >> word;
        if(word != ".")
        {
            vocabulary.push_back(word);
        }
    }
    return vocabulary;
}

string choose(vector<string> wordlist)
{
    srand(time(NULL));
    int numofwords = wordlist.size();
    int chosenindex = rand()%numofwords;
    string chosenword = wordlist.at(chosenindex);
    return chosenword;
}

void initgame(string currentword,char gamearr[])
{
    int wordlength = currentword.length();
    for(int i = 0; i < wordlength; i++)
    {
        cout << "_";
        gamearr[i] = '_';
    }
    cout << endl;
    cout << "Moi nhap ket qua can doan: ";
}

void processgame(char input, string currentword,char gamearr[],int &remainingblanks,int &lives)
{
    int wordlength = currentword.length();
    bool isCorrect = false;
    for(int i = 0; i < wordlength; i++)
    {
        if(input == currentword[i] && gamearr[i] == '_')
        {
            gamearr[i] = input;
            remainingblanks--;
            isCorrect = true;
        }
    }
    if(!isCorrect)
    {
        lives--;
        cout << "Khong co tu nao hop le, con " << lives << " luot doan" << endl;
    }
    for(int i = 0; i < wordlength; i++)
    {
        cout << gamearr[i];
    }
    cout << endl;
}

int main()
{
    string test = "?";
    int lives = 10;
    char playerchoice;
    vector<string> dictionary = initvocab(test);
    string chosen = choose(dictionary);
    int arrlength = chosen.length();
    char gamearr[arrlength];
    int blanks = arrlength;
    initgame(chosen,gamearr);
    while(lives > 0 && blanks > 0)
    {
        cin >> playerchoice;
        cout << endl;
        processgame(playerchoice,chosen,gamearr,blanks,lives);
    }
    if(lives == 0)
    {
        cout << "GAME OVER!" << endl;
    }else if(blanks == 0)
    {
        cout << "YOU WON!" << endl;
    }
    return 0;
}
