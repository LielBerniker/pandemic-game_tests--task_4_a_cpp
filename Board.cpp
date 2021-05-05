#include "Board.hpp"
using namespace std;
using namespace pandemic;

namespace pandemic
{
    void Board::remove_cures()
    {
          for (auto &element : cure_pandemic)
        {
            string color = element.first;
            cure_pandemic[color] = false; 
        }
    }
    void Board::insert_city_info(ifstream &cities_file)
    {
        size_t i = 0;
        string line;
        while (getline(cities_file, line))
        {
            string city_key;
            string color;
            string city_temp;
            i = 0;
            while (line.at(i) != ' ')
            {
                city_key += line.at(i);
                i++;
            }
            i++;
            while (line.at(i) != ' ')
            {
                color += line.at(i);
                i++;
            }
            city_cube[city_key] = 0;
            city_color[city_key] = color;
            city_station[city_key] = false;
            i++;
            while (i < line.length())
            {
                while (line.at(i) != ' ')
                {
                    city_temp += line.at(i);
                    i++;
                }
                city_conect[city_key].push_back(city_temp);
                i++;
            }
        }
    }
    ostream &operator<<(ostream &out,  Board &board)
    {
         for (auto &element : board.city_cube)
        {
            string city_name = element.first;
            int city_cubes = element.second;
            string city_color = board.city_color[city_name];
            bool station_in = board.city_station[city_name];
              out << "city " << city_name << "has number of " << city_cubes << " " << city_color<<" cubes\n";
            if (station_in)
            {
                out << "the city do have a Research station\n";
            }
            out << "\n";
        }

        return out;
    }
    int &Board::operator[](City city)
    {

        return this->city_cube[city_str[city]];
    }
    bool Board::is_clean()
    {
        for (auto &element : city_cube)
        {
            if (element.second != 0)
            {
                return false;
            }
        }
        return true;
    }
    Board::Board()
    {
    }
    map<City,string> Board::city_str{{City::Algiers,"Algiers"}, {City::Atlanta,"Atlanta"}, {City::Baghdad,"Baghdad"}, {City::Bangkok,"Bangkok"}, {City::Beijing,"Beijing"},  {City::Bogota,"Bogota"}, {City::BuenosAires,"BuenosAires"}, {City::Cairo,"Cairo"}, {City::Chennai,"Chennai"}, {City::Chicago,"Chicago"}, {City::Delhi,"Delhi"}, {City::Essen,"Essen"}, {City::HoChiMinhCity,"HoChiMinhCity"}, {City::HongKong,"HongKong"}, {City::Istanbul,"Istanbul"}, {City::Jakarta,"Jakarta"}, {City::Johannesburg,"Johannesburg"}, {City::Karachi,"Karachi"}, {City::Khartoum,"Khartoum"}, {City::Kinshasa,"Kinshasa"}, {City::Kolkata,"Kolkata"}, {City::Lagos,"Lagos"}, {City::Lima,"Lima"}, { City::London,"London"}, {City::LosAngeles,"LosAngeles"}, {City::Madrid,"Madrid"}, {City::Manila,"Manila"}, {City::MexicoCity,"MexicoCity"}, {City::Miami,"Miami"}, {City::Milan,"Milan"}, {City::Montreal,"Montreal"}, {City::Moscow,"Moscow"}, {City::Mumbai,"Mumbai"}, {City::NewYork,"NewYork"}, {City::Osaka,"Osaka"}, {City::Paris,"Paris"}, {City::Riyadh,"Riyadh"}, {City::SanFrancisco,"SanFrancisco"}, {City::Santiago,"Santiago"}, {City::SaoPaulo,"SaoPaulo"}, {City::Seoul,"Seoul"}, {City::Shanghai,"Shanghai"}, {City::StPetersburg,"StPetersburg"}, {City::Sydney,"Sydney"}, {City::Taipei,"Taipei"}, {City::Tehran,"Tehran"}, {City::Tokyo,"Tokyo"}, {City::Washington,"Washington"}};
    map<Color,string> Board::color_str
    {
        {Color::Blue,"Blue"}, {Color::Black,"Black"}, {Color::Red,"Red"}, { Color::Yellow,"Yellow"}
    };
}
