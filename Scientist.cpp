#include "Scientist.hpp"
using namespace std;
using namespace pandemic;

namespace pandemic
{
  Scientist::Scientist(Board board,City city,int num):Player(board,city)
   {
     player_role = "Scientist";
     card_num = num;
   }

}
