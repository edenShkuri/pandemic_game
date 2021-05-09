#include <iostream>
#include <stdexcept>
#include <string>
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "FieldDoctor.hpp"

using namespace std;

namespace pandemic{
    Player& FieldDoctor::treat(City city){
        if(board[city] == 0){
            throw invalid_argument{"the disease level in "+enumCity_to_str(city)+" is 0"};
        }
        if(city != myCity && !is_neighbors(city, myCity)){
            throw invalid_argument{"you are not in or next to "+enumCity_to_str(city)};
        }
        if(get_Cure(city)){
            board[city] = 0;
        }
        else{board[city]--;}

        cout<<"treat in "<<enumCity_to_str(city)<<endl;
        return *this;
    }

}