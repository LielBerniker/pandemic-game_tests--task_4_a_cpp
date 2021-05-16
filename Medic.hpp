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
  Medic(pandemic::Board &board,pandemic::City city);
    virtual Medic &drive(pandemic::City city);
    virtual Medic &fly_direct(pandemic::City city);
    virtual Medic &treat(pandemic::City city);
    virtual Medic &fly_charter(pandemic::City city);
    virtual Medic &fly_shuttle(pandemic::City city);
    virtual void discover_cure(pandemic::Color color);
    virtual std::string role();
    protected:
    void update_cubes();

    };
 
}