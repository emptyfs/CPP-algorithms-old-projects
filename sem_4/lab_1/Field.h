#pragma once

#include <vector>
#include <iostream>
#include "Square.h"

class Field
{
private:
    std::vector <Square> squares;
    std::vector <Square> local_squares;
    int main_size = 0;
    int square_number = 0;
    int operation_amount = 0;
public:
    void backtracking(int);
    void add_vector_local_squares(int, int, int);
    void set_deafult_local_squares(int, int**);
    void set_main_size(int);
    void fill_empty_square(int**, int, int, int, int);
    bool check_matrix(int**, int, int&, int&);
    int find_side(int**, int, int, int);
    void back_vector(int**, int&, int&);
    void print_squares();
};