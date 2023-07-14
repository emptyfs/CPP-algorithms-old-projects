#include "Edge.h"

Edge::Edge() = default;

Edge::Edge(int left_vertex, int right_vertex, float edge_amount) : left_vertex(left_vertex), 
right_vertex(right_vertex), edge_amount(edge_amount) {}
