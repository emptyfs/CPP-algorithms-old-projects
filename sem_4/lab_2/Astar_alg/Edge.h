#pragma once

class Edge //класс ребер
{
private:
    int left_vertex = 10000; //первая вершина ребра
    int right_vertex = 10000; //вторая вершина ребра
    float edge_amount = 0; //вес ребра

public:
    Edge();
    Edge(int, int, float);

    friend class ASTAR_alg;
};