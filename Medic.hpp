#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
namespace pandemic
{
    class Medic:public Player
    {
      public:
  Medic(pandemic::Board board,pandemic::City city);


    };
 
}