#pragma once
namespace pandemic{
    static const std::string Color_str[] ={"Red", "Black", "Yellow", "Blue"};
    typedef enum Color{Red, Black, Yellow, Blue}Color;
    inline std::string enumColor_to_str(Color C){
        return Color_str[C];
    }
}