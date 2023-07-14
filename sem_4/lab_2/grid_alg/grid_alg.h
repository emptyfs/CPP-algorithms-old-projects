#pragma once

#include "Edge.h"
#include <vector>
#include <iostream>

class grid_alg
{
private:
    char local_start_vertex = '\0'; //начальная текущая вершина
    char finish_vertex = '\0'; //конечная вершина
    std::vector<Edge> graph; //вектор всех поданных на вход ребер
    Edge local_min_edge; //текущий минимальный вес ребра
public:
    void add_edge(char, char, float); //для начального заполнения графа
    void set_start_finish_vertexes(char, char); //для начального заполнения полей начальной и конечной вершин
    void alg(); //основная часть "жадного" алгоритма
};