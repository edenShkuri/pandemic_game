#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

using namespace std;

namespace pandemic{
    class FieldDoctor: public Player{
          public:
            FieldDoctor(Board &b, City c): Player(b,c){
              myRole="FieldDoctor";
            };
            Player& treat(City city) override;

    };
}