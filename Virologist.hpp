#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
namespace pandemic
{
    class Virologist:public Player
    {
      public:
  Virologist(pandemic::Board &board,pandemic::City city);
  virtual Virologist &treat(pandemic::City city);
  virtual std::string role();


    };
 
}