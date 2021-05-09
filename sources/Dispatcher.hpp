#include <iostream>
#include <stdexcept>
#include <string>
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

using namespace std;

namespace pandemic{
    class Dispatcher: public Player{
        public:
            Dispatcher(Board &b, City c): Player(b,c){
                myRole="Dispatcher";
            };
            Player& fly_direct(City city) override;

    };
}