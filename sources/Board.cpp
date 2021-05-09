#include <iostream>
#include <stdexcept>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"

using namespace std;

namespace pandemic{
    
    map<string,tuple <vector<string>, string, int, bool, bool>>::iterator it;
    // tuple order - Neighboring cities, Color, Disease level, Research station, Cure


    Board::Board(){
        Cures.insert(make_pair(Color::Red, false));
        Cures.insert(make_pair(Color::Blue, false));
        Cures.insert(make_pair(Color::Black, false));
        Cures.insert(make_pair(Color::Yellow, false));

       ifstream cities_file{"cities_map.txt"};
       string line;
       while(getline(cities_file, line))
       {
           
           string CityName = line.substr(0, line.find(' '));
           string right = line.substr(line.find(' ')+1, line.length());
           string color = right.substr(0, right.find(' '));
           string Neighbors = right.substr(right.find(' '), right.length());
      
           std::vector<std::string> v;
           while(Neighbors.find(' ')<Neighbors.length()){               
               string nei = Neighbors.substr(0, Neighbors.find(' '));
               v.push_back(nei);
               Neighbors=Neighbors.substr(Neighbors.find(' ')+1, right.length());
           }
           v.push_back(Neighbors);
           tuple <vector<string>, string, int, bool, bool> t= make_tuple(v, color, 0, false, false);
           pair<string, tuple <vector<string>, string, int, bool, bool>> p=make_pair(CityName, t);
           myBoard.insert(p);
        }
    }

    int& Board::operator[](const City C){  
        return (get<2>(myBoard[enumCity_to_str(C)]));
    }


    /**--City Name--
    *Neighboring cities:
    *             Color: 
    *     Disease level:
    *  Research station:
    *              Cure:
    */
    ostream& operator<<(std::ostream& os, const Board &b){
    
        cout<<endl<<"              --THE BOARD--"<<endl;
        for(const auto& itr:b.myBoard){
            string CityName= (itr.first)+"\n--------------------------------------\n";
            string s="Neighboring cities: ";
            size_t size =(get<0>(itr.second)).size();
            int i=0;
            for(const auto& value: (get<0>(itr.second))) {
                s+= value;
                if((i<size-1) && i>0){
                    s+=", ";
                }         
                i++;
            }     
            os <<CityName<<s<<endl;
            os<<"             Color: "<< (get<1>(itr.second))<<endl;
            os<<"     Disease level: "<<to_string(get<2>(itr.second))<<endl;
            os << boolalpha;
            os<<"  Research station: "<<(get<3>(itr.second))<<endl;
            os<<"              Cure: "<<(get<4>(itr.second))<<endl<<endl;
        }
        return os;
    }

    bool Board::is_clean(){
        for (it = myBoard.begin(); it != myBoard.end(); it++)
        {
          if(get<2>(myBoard[it->first])!=0){
              return false;
          }
        }
        return true;
    }

    void Board::remove_cures(){
       for (it = myBoard.begin(); it != myBoard.end(); it++)
        {
          get<4>(myBoard[it->first])=false;
        }
        Cures[Color::Yellow]=false;
        Cures[Color::Black]=false;
        Cures[Color::Blue]=false;
        Cures[Color::Red]=false;
    }

    void Board::remove_stations(){
        for (it = myBoard.begin(); it != myBoard.end(); it++)
        {
          get<3>(myBoard[it->first])=false;
        }
     
    }


}
