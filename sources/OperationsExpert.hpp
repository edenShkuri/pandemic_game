#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

using namespace std;

namespace pandemic{
    class OperationsExpert: public Player{
        public:
            OperationsExpert(Board &b, City c): Player(b,c){            
                myRole="OperationsExpert";
            };
            Player& build() override;

    };
}