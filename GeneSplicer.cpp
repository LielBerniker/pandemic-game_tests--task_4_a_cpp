#include "GeneSplicer.hpp"
#include "Player.hpp"
using namespace std;
using namespace pandemic;

namespace pandemic
{
    GeneSplicer::GeneSplicer(Board &board, City city) : Player(board, city)
    {
    }
    void GeneSplicer::discover_cure(Color color)
    {
        string color_temp = Board::get_color_str(color);
        if (game_board.get_cure_pandemic(color_temp))
        {
            return;
        }
        if (all_cards.size() < pandemic::FIVE || (!game_board.get_city_lab(current_city)))
        {
            throw out_of_range(pandemic::DISCOVER_CURE);
        }
        int i = 0;
        for (auto it = all_cards.begin(); it != all_cards.end();)
        {
            all_cards.erase(it++);
            i++;
            if (i == pandemic::FIVE)
            {
                break;
            }
        }
        game_board.set_cure_pandemic(color_temp, true);
    }
    string GeneSplicer::role()
    {
        return "GeneSplicer";
    }

}
