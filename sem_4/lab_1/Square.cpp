#include "Square.h"

Square::Square() = default;

Square::Square(int s, int x, int y) : side(s), x(x), y(y) {}

void Square::set_side(int side)
{
    this->side = side;
}

void Square::set_x(int x)
{
    this->x = x;
}

void Square::set_y(int y)
{
    this->y = y;
}

int Square::get_x()
{
    return x;
}

int Square::get_y()
{
    return y;
}

int Square::get_side()
{
    return side;
}