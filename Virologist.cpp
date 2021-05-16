#include "Virologist.hpp"
using namespace std;
using namespace pandemic;

namespace pandemic
{
  Virologist::Virologist(Board &board, City city) : Player(board, city)
  {
  }
  Virologist &Virologist::treat(City city)
  {
    if (game_board[city] == 0)
    {
      throw out_of_range(pandemic::TREAT_CiTY);
    }
    string city_color = game_board.get_city_color(city);
    if (current_city != city)
    {
      if (all_cards.find(city) != all_cards.end())
      {
        all_cards.erase(city);
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
  string Virologist::role()
  {
    return "Virologist";
  }

}
