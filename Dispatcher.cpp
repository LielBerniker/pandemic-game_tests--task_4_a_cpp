#include "Dispatcher.hpp"
using namespace std;
using namespace pandemic;

namespace pandemic
{
   Dispatcher::Dispatcher(Board &board, City city) : Player(board, city)
   {
   }
   Dispatcher &Dispatcher::fly_direct(City city)
   {
      if (current_city == city)
      {
         throw out_of_range(pandemic::FLY_CITY);
      }
      if (game_board.get_city_lab(current_city))
      {
         current_city = city;
      }
      else
      {
         Player::fly_direct(city);
      }

      return *this;
   }
   string Dispatcher::role()
   {
      return "Dispatcher";
   }
}
