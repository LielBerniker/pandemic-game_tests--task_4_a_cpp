#include "Medic.hpp"
#include "Player.hpp"
using namespace std;
using namespace pandemic;

namespace pandemic
{
   Medic::Medic(Board &board, City city) : Player(board, city)
   {
   }
  Medic &Medic::treat(City city)
   {
      if (current_city != city || game_board[city] == 0)
      {
         throw out_of_range(pandemic::TREAT_CiTY);
      }
      game_board[city] = 0;

      return *this;
   }
   void Medic::discover_cure(Color color)
   {
      Player::discover_cure(color);
      update_cubes();
   }
   Medic &Medic::drive(City city)
   {
      Player::drive(city);
      update_cubes();
      return *this;
   }
  Medic &Medic::fly_direct(City city)
   {
      Player::fly_direct(city);
      update_cubes();
      return *this;
   }
  Medic &Medic::fly_charter(City city)
   {
     Player::fly_charter(city);
      update_cubes();
      return *this;
   }
  Medic &Medic::fly_shuttle(City city)
   {
      Player::fly_shuttle(city);
      update_cubes();
      return *this;
   }
   string Medic::role()
   {
    return "Medic";
   }
   void Medic::update_cubes()
   {
      string color_temp = game_board.get_city_color(current_city);
      if (game_board.get_cure_pandemic(color_temp))
      {
         game_board[current_city] = 0;
      }
   }

}
