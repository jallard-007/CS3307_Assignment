#ifndef GAME_H
#define GAME_H
#include <string>

class Game {
  private:
    std::string m_homeName;
    std::string m_awayName;
    int m_homeScore;
    int m_awayScore;

  public:
    Game();
    ~Game() = default;
    void setHomeName(std::string);
    void setAwayName(std::string);
    void setHomeScore(int);
    void setAwayScore(int);
    void printGame();
    bool isValid();

};

#endif