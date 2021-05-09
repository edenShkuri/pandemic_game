#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

using namespace std;

namespace pandemic{
    class GeneSplicer: public Player{
        bool throw_5_cards();

        public:
            GeneSplicer(Board &b, City c): Player(b,c){
                myRole="GeneSplicer";
            };
            Player& discover_cure(Color color) override;

    };
}