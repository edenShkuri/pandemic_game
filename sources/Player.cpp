#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

const int cards_to_throw=5;

using namespace std;

namespace pandemic{ 
    map<string,tuple <vector<string>, string, int, bool, bool>>::iterator it1;


    void Player::remove_cards(){
        cards.clear();
    }


    map<Color, bool> Player::get_Cures_by_Colors(){
        return board.Cures;
    }


    bool Player::is_neighbors(City a, City b){
        vector<string> v=(get<0>(board.myBoard[enumCity_to_str(a)])); 
            return (find(v.begin(), v.end(), enumCity_to_str(b)) != v.end());
    }

    bool& Player::get_Research_station(const City c){
        return get<3>(board.myBoard[enumCity_to_str(c)]);
    }
    
  
    bool Player::get_Cure(City c){
        return get<4>(board.myBoard[enumCity_to_str(c)]);
    }
    
    string Player::get_Color(City c){       
        return get<1>(board.myBoard[enumCity_to_str(c)]);
    }

    void Player::update_Cure(Color color){
    
        for (it1= board.myBoard.begin(); it1 != board.myBoard.end(); it1++)
        {
         if(get<1>(it1->second)==enumColor_to_str(color)){
            get<4>(it1->second)=true;
         }   
        }
        board.Cures[color]=true;
    }
    
    bool Player::throw_n_cards_in(Color color, int n){
        vector<City> cards_to_throw;
        int cards_added=0;
        for(const auto& card: cards) {
            if(cards_added==n){ break;}
            if(get_Color(card)==enumColor_to_str(color)){
                cards_to_throw.push_back(card);
                cards_added++;
            }        
        }     
        if(cards_added==n){
            for(const auto& c: cards_to_throw) {
                cards.erase(find(cards.begin(), cards.end(), c));
            }
            return true;
        }
    return false;
    }


    Player& Player::drive(City city){
        if(city==myCity){
            throw invalid_argument{"you can't drive to where you are right now"};
        }
        if(this->is_neighbors(city, myCity)){
            myCity=city;
        }
        else{throw invalid_argument{"can't drive to not-neighbor city (from "+
        enumCity_to_str(myCity)+" to "+enumCity_to_str(city)};}
        cout<<"drive to "<<enumCity_to_str(city)<<endl;
        return *this;
    }

    Player& Player::fly_direct(City city){
        if(city==myCity){
            throw invalid_argument{"you can't fly to where you are right now"};
        }
        if(find(cards.begin(), cards.end(), city) != cards.end()){
            cards.erase(find(cards.begin(), cards.end(), city));
            myCity=city;
        }
        else{throw invalid_argument{"you don't have the card \""+enumCity_to_str(city)+"\"\n"};}
        
        cout<<"fly_direct to "<<enumCity_to_str(city)<<endl;    
        return *this;            
    }

    Player& Player::fly_charter(City city){
        if(city==myCity){
            throw invalid_argument{"you can't fly to where you are right now"};
        }
        if(find(cards.begin(), cards.end(), myCity) != cards.end()){
            cards.erase(find(cards.begin(), cards.end(), myCity));
            myCity=city;
        }
        else{ throw invalid_argument{"you don't have the card \""+enumCity_to_str(myCity)+"\"\n"};}
        
        cout<<"fly_charter to "<<enumCity_to_str(city)<<endl;
        return *this;
    }

    Player& Player::fly_shuttle(City city){
        if(city==myCity){
            throw invalid_argument{"you can't fly to where you are right now"};
        }
        if(!get_Research_station(city)){
            throw invalid_argument{"\""+enumCity_to_str(city)+"\"don't have a research station\n"};
        }
        if(!get_Research_station(myCity)){
            throw invalid_argument{"your city - \""+enumCity_to_str(city)+"\"don't have a research station\n"};
        }
        myCity=city;
        cout<<"fly_shuttle to "<<enumCity_to_str(city)<<endl;
        return *this;
    }

    Player& Player::build(){
        if(!get_Research_station(myCity)){
            if(find(cards.begin(), cards.end(), myCity) != cards.end()){
                get_Research_station(myCity)=true;
                cards.erase(find(cards.begin(), cards.end(), myCity));
                cout<<"build Research station at "<<enumCity_to_str(myCity)<<endl;
            }
            else{ throw invalid_argument{"you don't have the card \""
                                    +enumCity_to_str(myCity)+"\"\n"};}
        }
        cout<<"there is a Research station at \""<<enumCity_to_str(myCity)<<"\"already"<<endl;
        return *this;
    }
    

    Player& Player::discover_cure(Color color){
        if(!board.Cures[color]){
            if(!get_Research_station(myCity)){
            throw invalid_argument{"no Research station in \""
                                    +enumCity_to_str(myCity)+"\""};
            }
            if(!throw_n_cards_in(color, cards_to_throw)){
            throw invalid_argument{"you dont have 5 "+enumColor_to_str(color)+" cards to throw"};
            }
            update_Cure(color);
            cout<<"discover_cure in "<<enumColor_to_str(color)<<endl;
            cout<<endl;
        }
        return *this;
    }

    Player& Player::treat(City city){
        if(board[city] == 0){
            throw invalid_argument{"the disease level in "+enumCity_to_str(city)+" is 0"};
        }
        if(city != myCity){
            throw invalid_argument{"you are not in "+enumCity_to_str(city)};
        }
        if(get_Cure(city)){
            board[city] = 0;
        }
        else{board[city]--;}

        cout<<"treat in "<<enumCity_to_str(city)<<endl;

        return *this;
    }

    string Player::role(){
        return myRole;
    }

    Player& Player::take_card(City city){
       if(find(cards.begin(),cards.end(), city) ==  cards.end()){
            cards.push_back(city);
            // cout<<"take_card - "<<enumCity_to_str(city)<<endl;
        }
        return *this;
    }
}