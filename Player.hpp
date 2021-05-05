#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <string>
#include <vector>
#include <algorithm> // conatain find

namespace pandemic
{
  class Player
  {
  protected:
    pandemic::Board game_board;
    pandemic::City current_city;
    std::vector<pandemic::City> all_cards;
    std::string player_role;

  public:
    Player(pandemic::Board& board, pandemic::City city);
    Player &take_card(pandemic::City city);
    void build();
    Player &drive(pandemic::City city);
    Player &fly_direct(pandemic::City city);
    Player &treat(pandemic::City city);
    Player &fly_charter(pandemic::City city);
    Player &fly_shuttle(pandemic::City city);
    void discover_cure(pandemic::Color color);
    std::string role();
  };

}