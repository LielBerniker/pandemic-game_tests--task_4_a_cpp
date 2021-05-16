#include "Researcher.hpp"
using namespace std;
using namespace pandemic;

namespace pandemic
{
    Researcher::Researcher(Board &board, City city) : Player(board, city)
    {
    }
    void Researcher::discover_cure(Color color)
    {
        string color_temp = Board::get_color_str(color);
        if (game_board.get_cure_pandemic(color_temp))
        {
            return;
        }
        if (card_amount(color_temp) < pandemic::FIVE)
        {
            throw invalid_argument(pandemic::DISCOVER_CURE);
        }
        drop_cards(color_temp, pandemic::FIVE);
        game_board.set_cure_pandemic(color_temp, true);
    }
    string Researcher::role()
    {
        return "Researcher";
    }

}
