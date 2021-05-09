#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Researcher.hpp"
const int cards_to_throw=5;


using namespace std;

namespace pandemic{
    Player& Researcher::discover_cure(Color color){
        if(!get_Cures_by_Colors()[color]){
            if(!throw_n_cards_in(color, cards_to_throw)){
                throw invalid_argument{"you dont have 5 "+enumColor_to_str(color)+" cards"};
            }
            update_Cure(color);
            cout<<"discover_cure in "<<enumColor_to_str(color)<<endl;
        }
        return *this;
    }
 
}