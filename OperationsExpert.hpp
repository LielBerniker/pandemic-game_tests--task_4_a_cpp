#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
namespace pandemic
{
    class OperationsExpert:public Player
    {
        public:
    OperationsExpert(pandemic::Board& board,pandemic::City city);
    virtual void build();
    virtual std::string role();
    };
    
 
}
