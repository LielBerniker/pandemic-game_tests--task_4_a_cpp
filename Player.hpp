#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <string>
#include <set> // include the set
#include <algorithm> // conatain find
#include <exception> // hold the exeptions

namespace pandemic
{
  const std::string TREAT_CiTY = "can't treat that city";
  const std::string DRIVE_CITY = "can't drive to that city";
  const std::string FLY_CITY = "can't fly to that city";
  const std::string LAB_BUILD = "can't build lab in the city";
  const std::string DISCOVER_CURE = "can't dicover cure for that color";
  const int FIVE = 5;
  const int ZERO = 0;
  const int ONE  = 1;

  class Player
  {
  protected:
    pandemic::Board&game_board;
    pandemic::City current_city;
    std::set<pandemic::City> all_cards;
    int card_amount(const std::string &color);
    void drop_cards(const std::string &color, int amount);

  public:
    Player( pandemic::Board &board, pandemic::City city);
    Player &take_card(pandemic::City city);
    virtual void build();
    virtual Player &drive(pandemic::City city);
    virtual Player &fly_direct(pandemic::City city);
    virtual Player &treat(pandemic::City city);
    virtual Player &fly_charter(pandemic::City city);
    virtual Player &fly_shuttle(pandemic::City city);
    virtual void discover_cure(pandemic::Color color);
    virtual std::string role() =0;
    void remove_cards();
  };

}