#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

using namespace std;

namespace pandemic{
    class Medic: public Player{
         public:
            Medic(Board &b, City c): Player(b,c){
                myRole="Medic";

            };
            Player& treat(City city)override;
            Player& fly_direct(City city)override;
            Player& drive(City city);
            Player& fly_charter(City city);
            Player& fly_shuttle(City city);
        
    };
}