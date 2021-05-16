#include "Player.hpp"
using namespace std;
using namespace pandemic;

namespace pandemic
{
    Player::Player(Board &board, City city) : game_board{board}, current_city{city}
    {
    }
    Player &Player::take_card(City city)
    {
        all_cards.insert(city);
        return *this;
    }
    void Player::build()
    {
        if (!game_board.get_city_lab(current_city))
        {
            if (all_cards.find(current_city) != all_cards.end())
            {
                game_board.set_city_lab(current_city, true);
                all_cards.erase(current_city);
            }
            else
            {
                throw out_of_range(pandemic::LAB_BUILD);
            }
        }
    }
    Player &Player::drive(City city)
    {
        if (current_city == city || !game_board.cities_connected(current_city, city))
        {
            throw out_of_range(pandemic::DRIVE_CITY);
        }
        current_city = city;
        return *this;
    }
    Player &Player::fly_direct(City city)
    {
        if (city == current_city || all_cards.find(city) == all_cards.end())
        {
            throw out_of_range(pandemic::FLY_CITY);
        }
        all_cards.erase(city);
        current_city = city;
        return *this;
    }
    Player &Player::treat(City city)
    {
        if (current_city != city || game_board[city] == pandemic::ZERO)
        {
            throw out_of_range(pandemic::TREAT_CiTY);
        }
        string city_color = game_board.get_city_color(city);
        if (game_board.get_cure_pandemic(city_color))
        {
            game_board[city] = pandemic::ZERO;
        }
        else
        {
            game_board[city] -= pandemic::ONE;
        }
        return *this;
    }
    Player &Player::fly_charter(City city)
    {
        if (current_city == city || all_cards.find(current_city) == all_cards.end())
        {
            throw out_of_range(pandemic::FLY_CITY);
        }
        all_cards.erase(current_city);
        current_city = city;
        return *this;
    }
    Player &Player::fly_shuttle(City city)
    {
        if (current_city == city || !game_board.get_city_lab(current_city) || !game_board.get_city_lab(city))
        {

            throw out_of_range(pandemic::FLY_CITY);
        }
        current_city = city;
        return *this;
    }
    void Player::discover_cure(Color color)
    {
        string color_temp = Board::get_color_str(color);
        if (!game_board.get_cure_pandemic(color_temp))
        {
            if (card_amount(color_temp) < pandemic::FIVE || !game_board.get_city_lab(current_city))
            {
                throw out_of_range(pandemic::DISCOVER_CURE);
            }
            drop_cards(color_temp, pandemic::FIVE);
            game_board.set_cure_pandemic(color_temp, true);
        }
    }
    void Player::remove_cards()
    {
        all_cards.clear();
    }

    int Player::card_amount(const string &color)
    {
        int count = 0;
        size_t i = 0;
        string temp_color;
        for (auto elem : all_cards)
        {
            temp_color = game_board.get_city_color(elem);
            if (temp_color == color)
            {
                count++;
            }
        }
        return count;
    }
    void Player::drop_cards(const string &color, int amount)
    {
        int droped = 0;
        size_t i = 0;
        string color_temp;

        for (auto it = all_cards.begin(); it != all_cards.end();)
        {
            color_temp = game_board.get_city_color(*it);
            if (color_temp == color)
            {
                all_cards.erase(it++);
                droped++;
                if (droped == amount)
                    {return;}
            }
            else
            {
                ++it;
            }
        }
    }

}
