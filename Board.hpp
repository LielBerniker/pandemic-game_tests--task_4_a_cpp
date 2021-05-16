#pragma once
#include <string> // string
#include <map>    // for the map data base
#include <iostream>
#include <vector>  // vector
#include <fstream> // file
#include "City.hpp"
#include "Color.hpp"

namespace pandemic
{
    class Board
    {
    public:
        Board();
        int &operator[](pandemic::City city);
        friend std::ostream &operator<<(std::ostream &out, Board &board);
        bool is_clean();
        void remove_cures();
       static std::string &get_city_str(pandemic::City city);
       static std::string &get_color_str(pandemic::Color color);
        bool cities_connected(pandemic::City city_from ,pandemic::City city_to);
        std::string &get_city_color(pandemic::City city);
        bool get_city_lab(pandemic::City city);
        void set_city_lab(pandemic::City city, bool flag);
        bool get_cure_pandemic(const std::string &color);
        void set_cure_pandemic(const std::string &color,bool flag);

    private:
        static std::map<pandemic::City, std::string> city_str;
        static std::map<pandemic::Color, std::string> color_str;
        std::map<std::string, int> city_cube;
        std::map<std::string, std::vector<std::string>> city_conect;
        std::map<std::string, std::string> city_color;
        std::map<std::string, bool> city_lab;
        std::map<std::string, bool> cure_pandemic{{"Blue", false}, {"Black", false}, {"Red", false}, {"Yellow", false}};
        void insert_city_info(std::ifstream &cities_file);
    };

}
