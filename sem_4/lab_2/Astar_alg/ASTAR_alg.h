#pragma once

#include "Vertex.h"
#include "Edge.h"
#include <vector>
#include <iostream>

class ASTAR_alg
{
private:
    int start_vertex = 10000;
    int finish_vertex = 10000; //конечная вершина
    std::vector<Edge> graph; //вектор всех поданных на вход ребер
    std::vector<Vertex> vertexes; //вектор "закрытых" вершин
    std::vector<Vertex> open; //вектор "открытых вершин"

public:
    void add_edge(int, int, float); //для начального заполнения графа
    void set_start_finish_vertexes(int, int); //для начального заполнения полей начальной и конечной вершин
    void alg(); //основная часть "A*" алгоритма
    int hueristics(int, int); // эвристический алгоритм
    Vertex min_open(); //текущая минимальная вершина с F
    void delete_vertex(int); //удаление открытой вершины
    bool check_vertexx(int, std::vector<Vertex>&);
    int find_vertexx(int, std::vector<Vertex>&);
    void print_recover(); //восстановить путь и вывести его
};