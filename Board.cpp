#include "Board.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

namespace ariel{
    string const message;
    void Board::post(int row, int col, Direction direction, std::string&& message){
        if(row < 0 || col < 0) throw("Location must be non-negative, please try again!");
    }
    
    std::string Board::read(int row, int col, Direction direction, int length){
        if(row < 0 || col < 0) throw("Location must be non-negative, please try again!");

        return "read board";
    }
    
    void Board::show(){

    }
}