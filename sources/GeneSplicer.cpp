#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "GeneSplicer.hpp"
const int cards_to_throw=5;
using namespace std;

namespace pandemic{

    bool GeneSplicer::throw_5_cards(){
        if(cards.size()>=cards_to_throw){
            for(size_t i=0; i<cards_to_throw; i++){
                cards.erase(cards.begin());
            }
        return true;
        }
        return false;           
    }

    Player& GeneSplicer::discover_cure(Color color){
        if(!get_Cures_by_Colors()[color]){
            if(!get_Research_station(myCity)){
            throw invalid_argument{"no Research station in \""
                                    +enumCity_to_str(myCity)+"\""};
            }
            if(!throw_5_cards()){
                throw invalid_argument{"you dont have 5 cards to throw"};
            }
            update_Cure(color);
            cout<<"discover_cure in "<<enumColor_to_str(color)<<endl;
        }
        return *this;
    }


}