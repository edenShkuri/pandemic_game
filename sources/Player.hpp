#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"

namespace pandemic{
    class Player{

        protected:
            std::string myRole;
            Board &board;
            std::vector<City> cards;
            City myCity;
            bool throw_n_cards_in(Color color, int n);
            bool& get_Research_station(const City c);
            bool is_neighbors(City a, City b);
            void return_card_to_pile(City city);
            std::string get_Color(City c);
            bool get_Cure(City c);
            void update_Cure(Color color);
            std::map<Color, bool> get_Cures_by_Colors();

        public:
            Player(Board &b, City c):board(b), myCity(c){
                myRole="Player";
            }

            Player& drive(City city);
            virtual Player& fly_direct(City city);
            Player& fly_charter(City city);
            Player& fly_shuttle(City city);
            virtual Player& build();
            virtual Player& discover_cure(Color color);
            virtual Player& treat(City city);
            std::string role();
            Player& take_card(City city);
            void remove_cards();

    };
}
