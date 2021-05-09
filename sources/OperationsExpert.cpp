#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "OperationsExpert.hpp"

using namespace std;

namespace pandemic{
    Player& OperationsExpert::build(){
        if(!get_Research_station(myCity)){
            get_Research_station(myCity)=true;
            cout<<"build Research station at "<<enumCity_to_str(myCity)<<endl;   
        }
        else{cout<<"there is a Research station at \""<<
                  enumCity_to_str(myCity)<<"\"already"<<endl;}
        return *this;
    }


}