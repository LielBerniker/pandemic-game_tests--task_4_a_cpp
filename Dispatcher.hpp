#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
namespace pandemic
{
    class Dispatcher:public Player
    {
        public:
   Dispatcher(pandemic::Board &board,pandemic::City city);
    virtual Dispatcher &fly_direct(pandemic::City city);
    virtual std::string role();


    };
 
}