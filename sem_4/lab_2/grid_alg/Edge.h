#pragma once

class Edge //класс ребер
{
private:
    char left_vertex = '\0'; //первая вершина ребра
    char right_vertex = '\0'; //вторая вершина ребра
    float edge_amount = 0; //вес ребра
public:
    Edge();
    Edge(char, char, float);
    void set_left_vertex(char);
    void set_right_vertex(char);
    void set_edge_amount(float);
    char get_left_vertex();
    char get_right_vertex();
    float get_edge_amount();
};