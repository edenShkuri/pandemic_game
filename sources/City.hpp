#pragma once
#include <string>
namespace pandemic{
    static const std::string City_str[] =
{"Algiers","Atlanta","Baghdad","Bangkok","Beijing","Bogota","BuenosAires"
,"Cairo","Chennai","Chicago","Delhi","Essen","HoChiMinhCity","HongKong",
"Istanbul","Jakarta","Johannesburg","Karachi","Khartoum","Kinshasa",
"Kolkata","Lagos","Lima","London","LosAngeles","Madrid","Manila",
"MexicoCity","Miami","Milan","Montreal","Moscow","Mumbai","NewYork","Osaka",
"Paris","Riyadh","SanFrancisco","Santiago","SaoPaulo","Seoul","Shanghai",
"StPetersburg","Sydney","Taipei","Tehran","Tokyo","Washington"};
    typedef enum City{
Algiers,
Atlanta,
Baghdad,
Bangkok,
Beijing,
Bogota,
BuenosAires,
Cairo,
Chennai,
Chicago,
Delhi,
Essen,
HoChiMinhCity,
HongKong,
Istanbul,
Jakarta,
Johannesburg,
Karachi,
Khartoum,
Kinshasa,
Kolkata,
Lagos,
Lima,
London,
LosAngeles,
Madrid,
Manila,
MexicoCity,
Miami,
Milan,
Montreal,
Moscow,
Mumbai,
NewYork,
Osaka,
Paris,
Riyadh,
SanFrancisco,
Santiago,
SaoPaulo,
Seoul,
Shanghai,
StPetersburg,
Sydney,
Taipei,
Tehran,
Tokyo,
Washington
    }City;

inline std::string enumCity_to_str(City C){
    return City_str[C];
}
    
// inline std::vector<City> get_cards_pile(){
//     std::vector<City> v={Algiers,Atlanta,Baghdad,Bangkok,Beijing,Bogota,
//                     BuenosAires,Cairo,Chennai,Chicago,Delhi,Essen,
//                     HoChiMinhCity,HongKong,Istanbul,Jakarta,Johannesburg,
//                     Karachi,Khartoum,Kinshasa,Kolkata,Lagos,Lima,London,
//                     LosAngeles,Madrid,Manila,MexicoCity,Miami,Milan,
//                     Montreal,Moscow,Mumbai,NewYork,Osaka,Paris,Riyadh,
//                     SanFrancisco,Santiago,SaoPaulo,Seoul,Shanghai,
//                     StPetersburg,Sydney,Taipei,Tehran,Tokyo,Washington};
//     return v;
// }   

}