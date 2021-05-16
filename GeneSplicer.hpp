#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
namespace pandemic
{
    class GeneSplicer: public Player
    {
        public:
    GeneSplicer(pandemic::Board &board,pandemic::City city);
     virtual void discover_cure(pandemic::Color color);
     virtual std::string role();


    };
 
}
