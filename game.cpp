#include <iostream>
#include "game.h"

Game::Game():
  m_homeName{}, m_awayName{},
  m_homeScore{}, m_awayScore{} {}

void Game::setHomeName(const std::string &homeName) {
  m_homeName.assign(homeName);
}

void Game::setAwayName(const std::string &awayName) {
  m_awayName.assign(awayName);
}

void Game::setHomeScore(int homeScore) {
  m_homeScore = homeScore;
}

void Game::setAwayScore(int awayScore) {
  m_awayScore = awayScore;
}

bool Game::isValid() const {
  return !m_homeName.empty();
}

void Game::printGame() const {
  std::cout << m_homeName + " vs. " + m_awayName + ": " << m_homeScore << " - " << m_awayScore << '\n';
}
