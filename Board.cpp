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
        size_t j = 0;
        string line;
        while (getline(cities_file, line))
        {
            string city_key;
            string color;
            string city_temp;
            i = 0;
            j = line.find_first_of(' ', i);
            city_key = line.substr(i, j - i);
            i = j + 1;
            j = line.find_first_of(' ', i);
            color= line.substr(i, j - i);
            i = j + 1;
            city_cube[city_key] = 0;
            city_color[city_key] = color;
            city_lab[city_key] = false;
            while (i < line.length())
            {
                if(line.find_first_of(' ', i)== string::npos)
                {
                    city_temp = line.substr(i);
                    j = line.length();
                }
                else
                {
                    j = line.find_first_of(' ', i);
                    city_temp = line.substr(i,j-i);
                }
                city_conect[city_key].push_back(city_temp);
                i = j + 1;
            }
        }
    }
    ostream &operator<<(ostream &out, Board &board)
    {
         out << "\nthe board show: \n";
        for (auto &element : board.city_cube)
        {
            string city_name_1 = element.first;
            int city_cube_1 = element.second;
            string city_color_1 = board.city_color[city_name_1];
            bool station_in = board.city_lab[city_name_1];
            out << "city " << city_name_1 << "has number of " << city_cube_1 << " " << city_color_1 << " cubes\n";
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
        ifstream city_file{"cities_map.txt"};
        insert_city_info(city_file);
    }
    string &Board::get_city_str(City city)
    {
        return city_str[city];
    }
    string &Board::get_color_str(Color color)
    {
        return color_str[color];
    }
    bool Board::cities_connected(City city_from, City city_to)
    {
        string city_f = get_city_str(city_from);
        string city_t = get_city_str(city_to);
        bool flag = false;
        if(find(city_conect[city_f].begin(), city_conect[city_f].end(), city_t) != city_conect[city_f].end())
        {flag = true;
        }
        return flag;
    }
    string &Board::get_city_color(City city)
    {
        string city_s = get_city_str(city);
        return city_color[city_s];
    }
    bool Board::get_city_lab(City city)
    {
        string city_s = get_city_str(city);
        return city_lab[city_s];
    }
    void Board::set_city_lab(City city, bool flag)
    {
        string city_s = get_city_str(city);
        city_lab[city_s] = flag;
    }
    bool Board::get_cure_pandemic(const string &color)
    {
        return cure_pandemic[color];
    }
    void Board::set_cure_pandemic(const string& color, bool flag)
    {
        cure_pandemic[color] = flag;
    }
  
    map<City, string> Board::city_str{{City::Algiers, "Algiers"}, {City::Atlanta, "Atlanta"}, {City::Baghdad, "Baghdad"}, {City::Bangkok, "Bangkok"}, {City::Beijing, "Beijing"}, {City::Bogota, "Bogota"}, {City::BuenosAires, "BuenosAires"}, {City::Cairo, "Cairo"}, {City::Chennai, "Chennai"}, {City::Chicago, "Chicago"}, {City::Delhi, "Delhi"}, {City::Essen, "Essen"}, {City::HoChiMinhCity, "HoChiMinhCity"}, {City::HongKong, "HongKong"}, {City::Istanbul, "Istanbul"}, {City::Jakarta, "Jakarta"}, {City::Johannesburg, "Johannesburg"}, {City::Karachi, "Karachi"}, {City::Khartoum, "Khartoum"}, {City::Kinshasa, "Kinshasa"}, {City::Kolkata, "Kolkata"}, {City::Lagos, "Lagos"}, {City::Lima, "Lima"}, {City::London, "London"}, {City::LosAngeles, "LosAngeles"}, {City::Madrid, "Madrid"}, {City::Manila, "Manila"}, {City::MexicoCity, "MexicoCity"}, {City::Miami, "Miami"}, {City::Milan, "Milan"}, {City::Montreal, "Montreal"}, {City::Moscow, "Moscow"}, {City::Mumbai, "Mumbai"}, {City::NewYork, "NewYork"}, {City::Osaka, "Osaka"}, {City::Paris, "Paris"}, {City::Riyadh, "Riyadh"}, {City::SanFrancisco, "SanFrancisco"}, {City::Santiago, "Santiago"}, {City::SaoPaulo, "SaoPaulo"}, {City::Seoul, "Seoul"}, {City::Shanghai, "Shanghai"}, {City::StPetersburg, "StPetersburg"}, {City::Sydney, "Sydney"}, {City::Taipei, "Taipei"}, {City::Tehran, "Tehran"}, {City::Tokyo, "Tokyo"}, {City::Washington, "Washington"}};
    map<Color, string> Board::color_str{
        {Color::Blue, "Blue"}, {Color::Black, "Black"}, {Color::Red, "Red"}, {Color::Yellow, "Yellow"}};
}
