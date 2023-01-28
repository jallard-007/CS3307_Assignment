/**
 * Game class implementation
 * Author: Justin Nicolas Allard
 * Date: Jan 27, 2023
*/

#include <iostream>
#include "game.h"

/**
 * Function name: Game::Game
 * Description: default constructor
 * Parameters: none
 * Return: none
*/
Game::Game():
  m_homeName{}, m_awayName{},
  m_homeScore{}, m_awayScore{} {}

/**
 * Function name: Game::setHomeName
 * Description:
 * Parameters: homeName - home team's name
 * Return: void
*/
void Game::setHomeName(const std::string &homeName) {
  m_homeName.assign(homeName);
}

/**
 * Function name: Game::setAwayName
 * Description:
 * Parameters: awayName - away team's name
 * Return: void
*/
void Game::setAwayName(const std::string &awayName) {
  m_awayName.assign(awayName);
}

/**
 * Function name: Game::setHomeScore
 * Description:
 * Parameters: homeScore - home team's score
 * Return: void
*/
void Game::setHomeScore(int homeScore) {
  m_homeScore = homeScore;
}

/**
 * Function name: Game::setAwayScore
 * Description:
 * Parameters: awayScore - away team's score
 * Return: void
*/
void Game::setAwayScore(int awayScore) {
  m_awayScore = awayScore;
}

/**
 * Function name: Game::printGame
 * Description: prints the object's information to stdout 
 * Parameters: none
 * Return: void
*/
void Game::printGame() const {
  std::cout << m_homeName + " vs. " + m_awayName + ": " << m_homeScore << " - " << m_awayScore << '\n';
}

/**
 * Function name: Game::isValid
 * Description: says if the object has complete information
 * Parameters: none
 * Return: true if complete, false otherwise
*/
bool Game::isValid() const {
  return !m_homeName.empty() && !m_awayName.empty() && m_homeScore >=0 && m_awayScore >= 0;
}
