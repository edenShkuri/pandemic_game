#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <map>
#include <vector>
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    class Board{

        protected:
            std::map<Color,bool> Cures;
            std::map<std::string,std::tuple <std::vector<std::string>, std::string, int, bool, bool>> myBoard;
            
        public:
            Board();
            friend class Player;   
            int& operator[] (const City C);
            friend std::ostream& operator<< (std::ostream& os, const Board& b);
            bool is_clean();
            void remove_cures();
            void remove_stations();
        
        };
}
