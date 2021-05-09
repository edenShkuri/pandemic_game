#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

using namespace std;

namespace pandemic{
    class Scientist: public Player{
        int throw_number;
        public:
            Scientist(Board &b, City c, int n): Player(b,c){
                throw_number=n;
                myRole="Scientist";
            };
            Player& discover_cure(Color color) override;


    };
}