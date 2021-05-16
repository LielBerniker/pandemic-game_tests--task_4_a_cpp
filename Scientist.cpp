#include "Scientist.hpp"
using namespace std;
using namespace pandemic;

namespace pandemic
{
  Scientist::Scientist(Board &board, City city, int num) : Player(board, city)
  {
    card_num = num;
  }
  void Scientist::discover_cure(Color color)
  {
    string color_temp = Board::get_color_str(color);
    if (game_board.get_cure_pandemic(color_temp))
    {
      return;
    }
    if (card_amount(color_temp) < card_num || !game_board.get_city_lab(current_city))
    {
      throw out_of_range(pandemic::DISCOVER_CURE);
    }
      drop_cards(color_temp, card_num);
      game_board.set_cure_pandemic(color_temp,true);
  }
  string Scientist::role()
  { 
    return "Scientist";
  }

}
