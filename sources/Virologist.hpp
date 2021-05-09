#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

using namespace std;

namespace pandemic{
    class Virologist: public Player{
        public:
            Virologist(Board &b, City c): Player(b,c){
                myRole="Virologist";
            };
            Player& treat(City city) override;
    };
}