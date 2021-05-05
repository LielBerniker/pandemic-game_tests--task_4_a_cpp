#include "Medic.hpp"
#include "Player.hpp"
using namespace std;
using namespace pandemic;

namespace pandemic
{
   Medic::Medic(Board board,City city):Player(board,city)
   {
      player_role = "Medic";
    
   }
 
}
