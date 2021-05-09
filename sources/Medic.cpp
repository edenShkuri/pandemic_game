#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Medic.hpp"

using namespace std;

namespace pandemic{
    Player& Medic::treat(City city){
        if(board[city] == 0){
            throw invalid_argument{"the disease level in "+enumCity_to_str(city)+" is 0"};
        }
        if(city != myCity){
            throw invalid_argument{"you are not in "+enumCity_to_str(city)};
        }
        
        board[city] = 0;
      
        cout<<"treat in "<<enumCity_to_str(city)<<endl;
        return *this;
    }

    Player& Medic::drive(City city){
        this->Player::drive(city);
        if(myCity==city && get_Cure(myCity)){
            board[city] = 0;
        }
        return *this;
    }

    Player& Medic::fly_direct(City city){
        this->Player::fly_direct(city);
        if(myCity==city && get_Cure(myCity)){
            board[city] = 0;
        }
        return *this;
    }

    Player& Medic::fly_charter(City city){
       this->Player::fly_charter(city);
        if(myCity==city && get_Cure(myCity)){
            board[city] = 0;
        }
        return *this;
    }

    Player& Medic::fly_shuttle(City city){
        this->Player::fly_shuttle(city);
        if(myCity==city && get_Cure(myCity)){
            board[city] = 0;
        }
        return *this;
    }

}