#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <string>
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Dispatcher.hpp"

using namespace std;

namespace pandemic{

    Player& Dispatcher::fly_direct(City city){
         if(city==myCity){
            throw invalid_argument{"you can't fly to where you are right now"};
        }
        cout<<"\nget_Research_station(myCity) = "<<get_Research_station(myCity)<<endl;
        if(get_Research_station(myCity)){
            myCity=city;
        }
        else if(find(cards.begin(), cards.end(), city) != cards.end()){
            cards.erase(find(cards.begin(), cards.end(), city));
            myCity=city;
        }
        else{ throw invalid_argument{"you don't have the card \""
                +enumCity_to_str(city)+"\" and your city does'nt have a research station\n"};}
        
        cout<<"fly_direct to "<<enumCity_to_str(city)<<endl;    
        return *this;            
    }

}