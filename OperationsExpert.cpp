#include "OperationsExpert.hpp"
using namespace std;
using namespace pandemic;

namespace pandemic
{
   OperationsExpert::OperationsExpert(Board &board, City city) : Player(board, city)
   {
   }
   void OperationsExpert::build()
   {
      game_board.set_city_lab(current_city, true);
   }
   string OperationsExpert::role()
   {
      return "OperationsExpert";
   }
}
