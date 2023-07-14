#include "ASTAR_alg.h"

void ASTAR_alg::print_recover()
{
    if (vertexes[vertexes.size() - 1].name != finish_vertex)
    {
        std::cout << "no way\n";
        return;
    }
    std::vector<int> result;
    Vertex current_vertex = vertexes[vertexes.size() - 1];
    while (true)
    {
        result.push_back(current_vertex.name);
        if (current_vertex.parent == 10000)
        {
            break;
        }
        current_vertex = vertexes[find_vertexx(current_vertex.parent, vertexes)];
    }
    for (int i = result.size() - 1; i >= 0; i--)
    {
        std::cout << result[i] << " ";
    }
}

int ASTAR_alg::find_vertexx(int name, std::vector<Vertex>& vertexx)
{
    int key = -1;
    for (int i = 0; i < vertexx.size(); i++)
    {
        if (vertexx[i].name == name)
        {
            key = i;
        }
    }
    return key;
}

bool ASTAR_alg::check_vertexx(int name, std::vector<Vertex>& vertexx)
{
    bool key = false;
    for (int i = 0; i < vertexx.size(); i++)
    {
        if (vertexx[i].name == name)
        {
            key = true;
        }
    }
    return key;
}


void ASTAR_alg::delete_vertex(int name)
{
    for (int i = 0; i < open.size(); i++)
    {
        if (open[i].name == name)
        {
            open.erase(open.begin() + i);
            i--;
        }
    }
}

Vertex ASTAR_alg::min_open()
{
    float min = open[0].way;
    Vertex min_F = Vertex(open[0].name, open[0].way_to_name, open[0].way_to_end, open[0].parent);
    for (int i = 1; i < open.size(); i++)
    {
        if (open[i].way < min || open[i].way == min && open[i].name > min_F.name)
        {
            min = open[i].way;
            min_F = Vertex(open[i].name, open[i].way_to_name, open[i].way_to_end, open[i].parent);
        }
    }
    return min_F;
}

int ASTAR_alg::hueristics(int name, int end)
{
    return abs(name - end);

}

void ASTAR_alg::alg()
{
    if (graph.empty()) //если граф пустой - путей нет
    {
        std::cout << "no way\n";
        return;
    }

    open.push_back(Vertex(start_vertex, 0, hueristics(start_vertex, finish_vertex), 10000));
    while (!open.empty())
    {
        bool tentative_is_better;
        Vertex current_vertex = min_open();
        if (open.empty()) //если граф пустой - путей нет
        {
            std::cout << "no way\n";
            return;
        }
        if (current_vertex.name == finish_vertex)
        {
            vertexes.push_back(current_vertex);
            break;
        }
        delete_vertex(current_vertex.name);
        vertexes.push_back(current_vertex);

        for (int i = 0; i < graph.size(); i++)
        {

            if (graph[i].left_vertex == current_vertex.name)
            {
                float temp_way_to_name_child = current_vertex.way_to_name + graph[i].edge_amount;
                if (check_vertexx(graph[i].right_vertex, vertexes))
                {
                    if (temp_way_to_name_child < vertexes[find_vertexx(graph[i].right_vertex, vertexes)].way)
                    {
                        vertexes[find_vertexx(graph[i].right_vertex, vertexes)].parent = graph[i].left_vertex;
                        vertexes[find_vertexx(graph[i].right_vertex, vertexes)].way_to_name = temp_way_to_name_child;
                        vertexes[find_vertexx(graph[i].right_vertex, vertexes)].way_to_end = hueristics(graph[i].right_vertex, finish_vertex);
                    }
                    continue;
                }
                if (!check_vertexx(graph[i].right_vertex, open))
                {
                    open.push_back(Vertex(graph[i].right_vertex, temp_way_to_name_child, hueristics((int)graph[i].right_vertex, (int)finish_vertex), graph[i].left_vertex));
                    tentative_is_better = true;
                }
                else
                {
                    if (temp_way_to_name_child < open[find_vertexx(graph[i].right_vertex, open)].way)
                    {
                        tentative_is_better = true;
                    }
                    else
                    {
                        tentative_is_better = false;
                    }
                    if (tentative_is_better)
                    {
                        open[find_vertexx(graph[i].right_vertex, open)].parent = graph[i].left_vertex;
                        open[find_vertexx(graph[i].right_vertex, open)].way_to_name = temp_way_to_name_child;
                        open[find_vertexx(graph[i].right_vertex, open)].way_to_end = hueristics(graph[i].right_vertex, finish_vertex);
                    }
                }
            }
        }
    }
    print_recover();
}

void ASTAR_alg::add_edge(int left_vertex, int right_vertex, float edge_amount)
{
    graph.push_back(Edge(left_vertex, right_vertex, edge_amount));
}

void ASTAR_alg::set_start_finish_vertexes(int start_vertex, int finish_vertex)
{
    this->start_vertex = start_vertex;
    this->finish_vertex = finish_vertex;
}