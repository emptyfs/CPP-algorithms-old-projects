#include <iostream>
#include "..\Vertex.h"
#include "..\Edge.h"
#include "..\ASTAR_alg.h"

int main()
{
    ASTAR_alg graph;
    int start_vertex; //начальная вершина
    int finish_vertex; //конечная вершина
    float edge_amount; //вес ребра

    std::cin >> start_vertex >> finish_vertex;
    graph.set_start_finish_vertexes(start_vertex, finish_vertex);

    while (std::cin >> start_vertex >> finish_vertex >> edge_amount)
    {
        if (edge_amount < 0)
        {
            std::cout << "no way\n";
            return 0;
        }
        graph.add_edge(start_vertex, finish_vertex, edge_amount); //заполнение вектора, элементы которого являются ребра (вершины + вес ребра), что отражает начальный граф
    }

    graph.alg();

    return 0;
}