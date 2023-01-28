/**
 * Main app
 * Author: Justin Nicolas Allard
 * Date: Jan 27, 2023
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>
#include "request.h"
#include "game.h"

#define FINAL "7" // game state of "7" means the game is over

/**
 * Function name: main
 * Description: Makes a request using the Request class to NHL's open data API
 *   for regular season info of the 2022-2023 year. The JSON is then
 *   parsed and Game objects are created for each played game, which
 *   are finally printed to stdout.
 * Parameters: none
 * Return: exit code
*/
int main() {
  Request request("https://statsapi.web.nhl.com/api/v1/schedule?season=20222023&gameType=R");
  if (!request.execute()) {
    return 0;
  }
  std::string result = request.getRes();
  nlohmann::json data = nlohmann::json::parse(result);
  std::vector<Game> games(data["totalGames"]); // allocating enough space for all games of the season
  size_t i = 0;
  for (const auto &date : data["dates"]) {
    for (const auto &game : date["games"]) {
      if (game["status"]["codedGameState"] != FINAL){ 
        continue; // the game has not completed yet, skip
      }

      nlohmann::json home = game["teams"]["home"];
      games[i].setHomeName(home["team"]["name"]);
      games[i].setHomeScore(home["score"]);

      nlohmann::json away = game["teams"]["away"];
      games[i].setAwayName(away["team"]["name"]);
      games[i].setAwayScore(away["score"]);

      ++i;
    }
  }

  for (const Game &game : games) {
    if (game.isValid()) {
      game.printGame();
    }
  }
}
