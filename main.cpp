#include <iostream>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>
#include "request.h"
#include "game.h"

int main() {
  Request request("https://statsapi.web.nhl.com/api/v1/schedule?season=20222023&gameType=R");
  request.execute();
  std::string result = request.getRes();
  nlohmann::json data = nlohmann::json::parse(result);
  std::vector<Game> games(data["totalGames"]);
  size_t i = 0;
  for (auto date : data["dates"]) {
    for (auto game : date["games"]) {
      if (game["status"]["codedGameState"] != "7"){
        continue;
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

  for (Game game : games) {
    if (game.isValid()) {
      game.printGame();
    }
  }
}
