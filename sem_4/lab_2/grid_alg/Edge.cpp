#include "Edge.h"

Edge::Edge() = default;

Edge::Edge(char left_vertex, char right_vertex, float edge_amount) : 
    left_vertex(left_vertex), right_vertex(right_vertex), edge_amount(edge_amount) {}

void Edge::set_left_vertex(char left_vertex)
{
    this->left_vertex = left_vertex;
}

void Edge::set_right_vertex(char right_vertex)
{
    this->right_vertex = right_vertex;
}

void Edge::set_edge_amount(float edge_amount)
{
    this->edge_amount = edge_amount;
}

char Edge::get_left_vertex()
{
    return left_vertex;
}

char Edge::get_right_vertex()
{
    return right_vertex;
}

float Edge::get_edge_amount()
{
    return edge_amount;
}