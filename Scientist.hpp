#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
namespace pandemic
{
    class Scientist:public Player
    { 
        private:
        int card_num;
        public:
    Scientist(pandemic::Board board,pandemic::City city,int num);
  
    };
 
}