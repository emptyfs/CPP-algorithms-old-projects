#include "grid_alg.h"

void grid_alg::alg()
{
    if (graph.empty()) //если граф пустой - путей нет
    {
        std::cout << "no way\n";
        return;
    }

    std::string vertex_string; //строка для вывода пути

    while (true)
    {
        local_min_edge.set_edge_amount(21000); //для нахождения минимального текущего веса ребра
        vertex_string += local_start_vertex; //запись в строку текущую рассматриваему вершину (из которой выходят ребра)

        if (local_start_vertex == finish_vertex) //цикл заканчивается, когда текущая рассматриваемя вершина - конечная вершина
        {
            break;
        }

        if (vertex_string.size() == 1 && graph.size() == 0) //если из начальной вершины нет ни одного пути в конечную вершину
        {
            std::cout << "no way\n";
            return;
        }

        for (int i = 0; i < graph.size(); i++) //поиск минимального ребра для текущей рассматриваемой вершины
        {
            if (local_start_vertex == graph[i].get_left_vertex() && graph[i].get_edge_amount() < local_min_edge.get_edge_amount())
            {
                local_min_edge.set_right_vertex(graph[i].get_right_vertex()); //фиксируется та вершина, в которое минимальное ребро ведет
                local_min_edge.set_edge_amount(graph[i].get_edge_amount()); //фиксируется вес минимального ребра
            }
        }

        if (local_min_edge.get_edge_amount() == 21000) //в случае, если у текущей рассматриваемой вершины нет пути в другие еще не рассмотренные вершины
        {
            local_start_vertex = vertex_string[vertex_string.size() - 2]; //"откат" назад - рассматривается ранее рассмотренная вершины, но без текущего ребра
            vertex_string.erase(vertex_string.size() - 2); //удаление этой вершины из списка
            continue;
        }


        local_start_vertex = local_min_edge.get_right_vertex(); //в случае, если минимальная нашлась: переход к вершине минимального ребра

        for (int i = 0; i < graph.size(); i++)
        {
            if (graph[i].get_right_vertex() == local_start_vertex) //удаляются все ребра, которые введут в рассматриваемую вершину
            {
                graph.erase(graph.begin() + i);
                i--;
            }
        }
    }

    std::cout << vertex_string;
}

void grid_alg::add_edge(char left_vertex, char right_vertex, float edge_amount)
{
    graph.push_back(Edge(left_vertex, right_vertex, edge_amount));
}

void grid_alg::set_start_finish_vertexes(char start_vertex, char finish_vertex)
{
    this->local_start_vertex = start_vertex;
    this->finish_vertex = finish_vertex;
}