#pragma once

class Square
{
private:
    int side = 0;
    int x = 0;
    int y = 0;
public:
    Square();
    Square(int, int, int);
    void set_side(int);
    void set_x(int);
    void set_y(int);
    int get_x();
    int get_y();
    int get_side();
};