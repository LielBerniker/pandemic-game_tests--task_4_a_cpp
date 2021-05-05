#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
namespace pandemic
{
    class FieldDoctor:public Player
    {
        public:
    FieldDoctor(pandemic::Board board,pandemic::City city);


    };
 
}
