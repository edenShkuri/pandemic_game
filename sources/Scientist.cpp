#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Scientist.hpp"


using namespace std;

namespace pandemic{
    Player& Scientist::discover_cure(Color color){
        if(!get_Cures_by_Colors()[color]){
            if(!get_Research_station(myCity)){
            throw invalid_argument{"no Research station in \""
                                    +enumCity_to_str(myCity)+"\""};
            }
            if(!throw_n_cards_in(color, throw_number)){
                throw invalid_argument{"you dont have "+to_string(throw_number)+" "+enumColor_to_str(color)+" cards to throw"};
            }
            update_Cure(color);
            cout<<"discover_cure in "<<enumColor_to_str(color)<<endl;
        }
        return *this;
    }
   
}