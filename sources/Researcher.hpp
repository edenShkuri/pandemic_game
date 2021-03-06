#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

using namespace std;

namespace pandemic{
    class Researcher: public Player{
        public:
            Researcher(Board &b, City c): Player(b,c){
            myRole="Researcher";
            };
            Player& discover_cure(Color color) override;

    };
}