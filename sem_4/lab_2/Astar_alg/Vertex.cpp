#include "Vertex.h"

Vertex::Vertex() = default;

Vertex::Vertex(int name, float way_to_name, float way_to_end, int parent) : name(name), way_to_name(way_to_name), 
way_to_end(way_to_end), parent(parent)
{
    way = way_to_name + way_to_end;
}