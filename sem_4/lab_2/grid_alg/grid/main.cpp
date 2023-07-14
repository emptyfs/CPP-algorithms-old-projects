#include <iostream>
#include "..\Edge.h"
#include "..\grid_alg.h"

int main()
{
    grid_alg graph;
    char start_vertex; //начальная вершина
    char finish_vertex; //конечная вершина
    float edge_amount; //вес ребра

    std::cin >> start_vertex >> finish_vertex;
    graph.set_start_finish_vertexes(start_vertex, finish_vertex); //установка полей начальной и конечной вершин

    while (std::cin >> start_vertex >> finish_vertex >> edge_amount)
    {
        graph.add_edge(start_vertex, finish_vertex, edge_amount); //заполнение вектора, элементы которого являются ребра (вершины + вес ребра), что отражает начальный граф
    }

    graph.alg();

    return 0;
}
