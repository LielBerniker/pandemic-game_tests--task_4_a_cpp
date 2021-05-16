#include "FieldDoctor.hpp"
using namespace std;
using namespace pandemic;

namespace pandemic
{
   FieldDoctor::FieldDoctor(Board &board, City city) : Player(board, city)
   {
   }
   FieldDoctor &FieldDoctor::treat(City city)
   {
      string city_color = game_board.get_city_color(city);
      if (game_board[city] == 0)
      {
         throw out_of_range(pandemic::TREAT_CiTY);
      }
      if (current_city != city)
      {
         if (game_board.cities_connected(current_city, city))
         {
            if (game_board.get_cure_pandemic(city_color))
            {
               game_board[city] = 0;
            }
            else
            {
               game_board[city] -= 1;
            }
         }
         else
         {
            throw out_of_range(pandemic::TREAT_CiTY);
         }
      }
      else
      {
         if (game_board.get_cure_pandemic(city_color))
         {
            game_board[city] = 0;
         }
         else
         {
            game_board[city] -= 1;
         }
      }
      return *this;
   }
   string FieldDoctor::role()
   {
      return "FieldDoctor";
   }

}
