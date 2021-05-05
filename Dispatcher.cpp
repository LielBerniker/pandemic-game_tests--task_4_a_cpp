#include "Dispatcher.hpp"
using namespace std;
using namespace pandemic;

namespace pandemic
{
   Dispatcher::Dispatcher(Board board,City city):Player(board,city)
   {
      player_role = "Dispatcher";
   }

}
