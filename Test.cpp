/**
 * AUTHOR: liel berniker
 * 
 */

#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

#include <sstream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <map>

using namespace pandemic;
using namespace std;

const unsigned int ZERO = 0, ONE = 1, TWO = 2, THEREE = 3, FOUR = 4, FIVE = 5;
const unsigned int SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10;
const unsigned int RAND_FOR = 4294967270, HOUNDRED = 100, FOUR_EIGHT = 48;
map<int, City> city_num{{0, City::Algiers}, {1, City::Atlanta}, {2, City::Baghdad}, {3, City::Bangkok}, {4, City::Beijing}, {5, City::Bogota}, {6, City::BuenosAires}, {7, City::Cairo}, {8, City::Chennai}, {9, City::Chicago}, {10, City::Delhi}, {11, City::Essen}, {12, City::HoChiMinhCity}, {13, City::HongKong}, {14, City::Istanbul}, {15, City::Jakarta}, {16, City::Johannesburg}, {17, City::Karachi}, {18, City::Khartoum}, {19, City::Kinshasa}, {20, City::Kolkata}, {21, City::Lagos}, {22, City::Lima}, {23, City::London}, {24, City::LosAngeles}, {25, City::Madrid},

                        {26, City::Manila},
                        {27, City::MexicoCity},
                        {28, City::Miami},
                        {29, City::Milan},
                        {30, City::Montreal},
                        {31, City::Moscow},
                        {32, City::Mumbai},
                        {33, City::NewYork},
                        {34, City::Osaka},
                        {35, City::Paris},
                        {36, City::Riyadh},
                        {37, City::SanFrancisco},
                        {38, City::Santiago},
                        {39, City::SaoPaulo},
                        {40, City::Seoul},
                        {41, City::Shanghai},
                        {42, City::StPetersburg},
                        {43, City::Sydney},
                        {44, City::Taipei},
                        {45, City::Tehran},
                        {46, City::Tokyo},
                        {47, City::Washington}};
TEST_CASE("Board [] method good tests")
{
    int i = 0;
    Board b1;
    for (i = 0; i < FOUR_EIGHT; i++)
    {
        CHECK(b1[city_num[i]] == 0);
    }
    b1[city_num[0]] = 3;
    b1[city_num[47]] = 4;
    CHECK_FALSE(b1[city_num[0]] == 0);
    CHECK_FALSE(b1[city_num[47]] == 0);
    CHECK(b1[city_num[0]] == 3);
    CHECK(b1[city_num[47]] == 4);
}
TEST_CASE("Board is_clean method good tests")
{
    int i = 0;
    Board b1;
    CHECK(b1.is_clean());
    b1[city_num[7]] = 10;
    CHECK_FALSE(b1.is_clean());
    b1[city_num[7]] = 0;
    CHECK(b1.is_clean());
    for (i = 0; i < FOUR_EIGHT; i++)
    {
        b1[city_num[i]] = 1;
        CHECK_FALSE(b1.is_clean());
    }
    for (i = 0; i < FOUR_EIGHT; i++)
    {
        b1[city_num[i]] = 0;
    }
    CHECK(b1.is_clean());
}
TEST_CASE("Player drive method tests")
{

    int i = 0;
    Board b1;
    Player player1(b1, City::Shanghai);
    CHECK_THROWS(player1.drive(City::Paris));
    CHECK_THROWS(player1.drive(City::Osaka));
    CHECK_THROWS(player1.drive(City::Manila));
    CHECK_NOTHROW(player1.drive(City::HongKong));
    CHECK_NOTHROW(player1.drive(City::Bangkok));
}
TEST_CASE("Player fly_direct method tests")
{
    int i = 0;
    Board b1;
    Player player1(b1, City::Shanghai);
    player1.take_card(City::Jakarta);
    player1.take_card(City::Manila);
    player1.take_card(City::Cairo);
    player1.take_card(City::Istanbul);
    CHECK_THROWS(player1.fly_direct(City::Paris));    // dont have paris city card
    CHECK_NOTHROW(player1.fly_direct(City::Jakarta)); //card of jakara should be droped
    CHECK_NOTHROW(player1.fly_direct(City::Manila));  //card of manila should be droped
    CHECK_THROWS(player1.fly_direct(City::Jakarta));  // dont have jakara card any more
    CHECK_NOTHROW(player1.fly_direct(City::Cairo));   // have cario card
    CHECK_NOTHROW(player1.fly_direct(City::Istanbul));
    CHECK_THROWS(player1.fly_direct(City::Cairo)); // dont have cario card any more
}
TEST_CASE("Player fly_charter method tests")
{
    int i = 0;
    Board b1;
    Player player1(b1, City::Shanghai);
    player1.take_card(City::Jakarta);
    player1.take_card(City::Istanbul);
    player1.take_card(City::Shanghai);
    CHECK_NOTHROW(player1.fly_charter(City::Paris)); // shuold throw Shanghai card
    CHECK_THROWS(player1.fly_charter(City::Taipei)); // dont have Shanghai card
    player1.take_card(City::Shanghai);
    CHECK_NOTHROW(player1.fly_charter(City::StPetersburg)); // shuold throw Shanghai card
}
TEST_CASE("Player build method tests")
{
    int i = 0;
    Board b1;
    Player player1(b1, City::Istanbul);
    player1.take_card(City::Jakarta);
    player1.take_card(City::Istanbul);
    player1.take_card(City::Shanghai);
    CHECK_NOTHROW(player1.build());                  // shuold throw istanbul card
    CHECK_THROWS(player1.fly_charter(City::Taipei)); // dont istanbul card
    player1.take_card(City::Istanbul);
    CHECK_NOTHROW(player1.fly_charter(City::Paris)); // shuold throw istanbul card
    CHECK_THROWS(player1.build());                   // dont istanbul card
}
TEST_CASE("Player discover_cure method tests")
{
    int i = 0;
    Board b1;
    b1[City::Santiago] = 3;
    Player player1(b1, City::Istanbul);
    player1.take_card(City::Jakarta);
    player1.take_card(City::Istanbul);
    player1.take_card(City::Shanghai);
    CHECK_THROWS(player1.discover_cure(Color::Yellow));
    player1.take_card(City::Kinshasa);
    player1.take_card(City::BuenosAires);
    player1.take_card(City::SaoPaulo);
    player1.take_card(City::MexicoCity);
    player1.take_card(City::Lima);
    CHECK_THROWS(player1.discover_cure(Color::Yellow));  //  dont have lab
    CHECK_THROWS(player1.discover_cure(Color::Black));   // dont have 5 black crads and dont have lab
    CHECK_NOTHROW(player1.build());                      // throw istanbul
    CHECK_NOTHROW(player1.discover_cure(Color::Yellow)); //  discover
    player1.take_card(City::Santiago);
    CHECK_NOTHROW(player1.fly_direct(City::Santiago)); //  discover
    player1.treat(City::Santiago);
    CHECK_FALSE(b1[City::Santiago] == 3);
    CHECK(b1[City::Santiago] == 0);
}
TEST_CASE("Player treat method tests")
{
    int i = 0;
    Board b1;
    b1[City::Santiago] = 3;
    Player player1(b1, City::Santiago);
    CHECK_THROWS(player1.treat(City::SaoPaulo));
    CHECK_NOTHROW(player1.treat(City::Santiago));
    CHECK(b1[City::Santiago] == 2);
    b1[City::Santiago] = 10;
    player1.take_card(City::Kinshasa);
    player1.take_card(City::BuenosAires);
    player1.take_card(City::SaoPaulo);
    player1.take_card(City::MexicoCity);
    player1.take_card(City::Lima);
    player1.take_card(City::SaoPaulo);
    CHECK_NOTHROW(player1.build());
    CHECK_NOTHROW(player1.discover_cure(Color::Yellow));
    CHECK_NOTHROW(player1.treat(City::Santiago));
    CHECK(b1[City::Santiago] == 0);
}
TEST_CASE("Player role method tests")
{
    int i = 0;
    Board b1;
    b1[City::Santiago] = 3;
    Player player1(b1, City::Istanbul);
    CHECK(player1.role() == "");
    Researcher player2(b1, City::Tehran);
    Scientist player3(b1, City::Tokyo, 5);
    FieldDoctor player4(b1, City::MexicoCity);
    GeneSplicer player5(b1, City::Miami);
    OperationsExpert player6(b1, City::Osaka);
    Dispatcher player7(b1, City::StPetersburg);
    Medic player8(b1, City::NewYork);
    Virologist player9(b1, City::Riyadh);
    CHECK(player2.role() == "Researcher");
    CHECK(player3.role() == "Scientist");
    CHECK(player4.role() == "FieldDoctor");
    CHECK(player5.role() == "GeneSplicer");
    CHECK(player6.role() == "OperationsExpert");
    CHECK(player7.role() == "Dispatcher");
    CHECK(player8.role() == "Medic");
    CHECK(player9.role() == "Virologist");
}
TEST_CASE("OperationsExpert build method tests")
{
    int i = 0;
    Board b1;
    OperationsExpert player1(b1, City::Istanbul);
    player1.take_card(City::Jakarta);
    CHECK_NOTHROW(player1.build());
    CHECK_NOTHROW(player1.fly_direct(City::Jakarta)); // throw jakarta card
    CHECK_NOTHROW(player1.build());
    CHECK_NOTHROW(player1.fly_shuttle(City::Istanbul)); // throw jakarta card
}
TEST_CASE("Dispatcher fly_direct method tests")
{
    int i = 0;
    Board b1;
    Dispatcher player1(b1, City::Shanghai);
    player1.take_card(City::Jakarta);
    player1.take_card(City::Istanbul);
    player1.take_card(City::Shanghai);
    CHECK_THROWS(player1.fly_direct(City::Paris));    // dont have paris city card and no lab
    CHECK_NOTHROW(player1.build());                   //card of shanghai should be droped
    CHECK_NOTHROW(player1.fly_direct(City::Paris));   //no card should be drop
    CHECK_NOTHROW(player1.fly_direct(City::Jakarta)); //card of jakara should be droped
    CHECK_NOTHROW(player1.build());
    CHECK_NOTHROW(player1.fly_direct(City::Manila)); //  no card should be drop
    CHECK_THROWS(player1.fly_direct(City::Lagos));   // dont have lagos city card and no lab
}
TEST_CASE("Scientist discover_cure method tests")
{
    int i = 0;
    Board b1;
    b1[City::Santiago] = 3;
    Scientist player1(b1, City::Istanbul, 3);
    player1.take_card(City::Jakarta);
    player1.take_card(City::Istanbul);
    CHECK_THROWS(player1.discover_cure(Color::Yellow)); // no lab and 3 cards yellow
     CHECK_THROWS(player1.discover_cure(Color::Red));// no lab and 3 cards red
     player1.take_card(City::Kinshasa);
    player1.take_card(City::BuenosAires);
    CHECK_THROWS(player1.discover_cure(Color::Yellow));// no lab and 3 cards red
    player1.take_card(City::SaoPaulo);
    CHECK_THROWS(player1.discover_cure(Color::Yellow));// no lab 
     CHECK_NOTHROW(player1.build()); //  have istanbul card
     CHECK_NOTHROW(player1.discover_cure(Color::Yellow));// no lab 
    player1.take_card(City::Santiago);
    CHECK_NOTHROW(player1.fly_direct(City::Santiago)); //  discover
    player1.treat(City::Santiago);
    CHECK_FALSE(b1[City::Santiago] == 3);
    CHECK(b1[City::Santiago] == 0);
}
TEST_CASE("Researcher discover_cure method tests")
{
    int i = 0;
    Board b1;
    b1[City::Santiago] = 3;
    Researcher player1(b1, City::Istanbul);
    player1.take_card(City::Jakarta);
    player1.take_card(City::Istanbul);
    player1.take_card(City::Shanghai);
    CHECK_THROWS(player1.discover_cure(Color::Yellow));
    player1.take_card(City::Kinshasa);
    player1.take_card(City::BuenosAires);
    player1.take_card(City::SaoPaulo);
    CHECK_THROWS(player1.discover_cure(Color::Yellow)); //  dont have 5 yellow cards
    player1.take_card(City::MexicoCity);
    player1.take_card(City::Lima);
    CHECK_THROWS(player1.discover_cure(Color::Black));   // dont have 5 black crads and dont have lab
    CHECK_NOTHROW(player1.discover_cure(Color::Yellow)); // have 5 yellow crads
    player1.take_card(City::Santiago);
    CHECK_NOTHROW(player1.fly_direct(City::Santiago)); //  discover
    player1.treat(City::Santiago);
    CHECK_FALSE(b1[City::Santiago] == 3);
    CHECK(b1[City::Santiago] == 0);
}
TEST_CASE("Medic treat method tests")
{
    int i = 0;
    Board b1;
    b1[City::Beijing] = 3;
    b1[City::Bangkok] = 10;
    b1[City::HongKong] = 70;
    Medic player1(b1, City::Beijing);
    CHECK_THROWS(player1.treat(City::SaoPaulo));
    CHECK_NOTHROW(player1.treat(City::Beijing));
    CHECK(b1[City::Beijing] == 0);
    b1[City::Beijing] = 10;
    player1.take_card(City::Jakarta);
    player1.take_card(City::Manila);
    player1.take_card(City::Seoul);
    player1.take_card(City::Shanghai);
    player1.take_card(City::Sydney);
    player1.take_card(City::Beijing);
    CHECK_NOTHROW(player1.build());
    CHECK_NOTHROW(player1.discover_cure(Color::Red));
    CHECK_NOTHROW(player1.treat(City::Beijing));
    CHECK(b1[City::Beijing] == 0);
    player1.take_card(City::Bangkok).take_card(City::HongKong);
    CHECK_NOTHROW(player1.fly_direct(City::Bangkok));
    CHECK(b1[City::Bangkok] == 0);
    CHECK_NOTHROW(player1.fly_direct(City::HongKong));
    CHECK(b1[City::HongKong] == 0);
}
TEST_CASE("Virologist treat method tests")
{
    int i = 0;
    Board b1;
    b1[City::Santiago] = 3;
    b1[City::BuenosAires] = 60;
    b1[City::Kolkata] = 8;
    Virologist player1(b1, City::Santiago);
    CHECK_THROWS(player1.treat(City::SaoPaulo)); // np card
    CHECK_NOTHROW(player1.treat(City::Santiago));
    CHECK(b1[City::Santiago] == 2);
    player1.take_card(City::BuenosAires).take_card(City::Kolkata);
    CHECK_NOTHROW(player1.treat(City::BuenosAires));
    CHECK(b1[City::BuenosAires] == 59);
    CHECK_THROWS(player1.treat(City::BuenosAires));// np card
    CHECK(b1[City::BuenosAires] == 59);
    CHECK_NOTHROW(player1.treat(City::Kolkata));  
    CHECK(b1[City::BuenosAires] == 7);
}
TEST_CASE("GeneSplicer discover_cure method tests")
{
    int i = 0;
    Board b1;
    b1[City::Riyadh] = 3;
    GeneSplicer player1(b1, City::Istanbul);
    player1.take_card(City::Jakarta);
    player1.take_card(City::Kinshasa);
    player1.take_card(City::SanFrancisco);
    player1.take_card(City::Tehran);
    CHECK_THROWS(player1.discover_cure(Color::Yellow));  // dont have 5 crads and dont have lab
    player1.take_card(City::Chicago);
    player1.take_card(City::Istanbul);
    CHECK_NOTHROW(player1.build()); 
    CHECK_NOTHROW(player1.discover_cure(Color::Black)); 
    player1.take_card(City::Riyadh);
    CHECK_NOTHROW(player1.fly_direct(City::Riyadh)); //  discover
    player1.treat(City::Riyadh);
    CHECK_FALSE(b1[City::Riyadh] == 3);
    CHECK(b1[City::Riyadh] == 0);
}
TEST_CASE("FieldDoctor treat method tests")
{
    int i = 0;
    Board b1;
    b1[City::Santiago] = 3;
    b1[City::BuenosAires] = 60;
    b1[City::Kolkata] = 8;
    FieldDoctor player1(b1, City::Santiago);
    CHECK_NOTHROW(player1.treat(City::Santiago));
    CHECK(b1[City::Santiago] == 2);
    player1.take_card(City::Bogota).take_card(City::Delhi);
    CHECK_NOTHROW(player1.fly_direct(City::Bogota));
    CHECK_NOTHROW(player1.treat(City::BuenosAires));
    CHECK(b1[City::BuenosAires] == 59);
    CHECK_NOTHROW(player1.fly_direct(City::Delhi));
    CHECK_NOTHROW(player1.treat(City::Kolkata));
    CHECK(b1[City::BuenosAires] == 7);
}