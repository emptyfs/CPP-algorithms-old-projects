#pragma once

class Vertex
{
private:
    int name = 10000;
    float way_to_name = 10000;
    float way_to_end = 10000;
    int parent = 10000;
    float way = 10000;
public:
    Vertex();
    Vertex(int, float, float, int);

    friend class ASTAR_alg;
};