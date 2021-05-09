#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Virologist.hpp"

using namespace std;

namespace pandemic{
    Player& Virologist::treat(City city){
       	if(board[city] == 0){
            throw invalid_argument{"the disease level in "+enumCity_to_str(city)+" is 0"};
        }
        if(city != myCity){
            if(find(cards.begin(),cards.end(), city) != cards.end()){
                cards.erase(find(cards.begin(),cards.end(), city));
            }
            else {throw invalid_argument{"you don't have the card of \""+enumCity_to_str(city)+"\""};}
        }
    
        if(get_Cure(city)){
            board[city] = 0;
        }
        else{board[city]--;}

        cout<<"treat in "<<enumCity_to_str(city)<<endl;
        return *this;
    }
}