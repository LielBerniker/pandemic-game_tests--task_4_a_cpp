#include "Player.hpp"
using namespace std;
using namespace pandemic;

namespace pandemic
{
    Player::Player(Board &board, City city) : game_board(board), current_city(city)
    {
        player_role = "";
    }
    Player &Player::take_card(City city)
    {
        if (find(all_cards.begin(), all_cards.end(), city) != all_cards.end())
        {
            all_cards.push_back(city);
        }
        return *this;
    }
    void Player::build()
    {
    }
    Player &Player::drive(City city)
    {
        return *this;
    }
    Player &Player::fly_direct(City city)
    {
        return *this;
    }
    Player &Player::treat(City city)
    {
        return *this;
    }
    Player &Player::fly_charter(City city)
    {
        return *this;
    }
    Player &Player::fly_shuttle(City city)
    {
        return *this;
    }
    void Player::discover_cure(Color color)
    {
    }
    std::string Player::role()
    {
        return player_role;
    }

}
