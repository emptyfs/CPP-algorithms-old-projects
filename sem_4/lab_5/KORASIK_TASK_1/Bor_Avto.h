#pragma once

#include <vector>
#include <cstring>
#include <iostream>
#include <map>
#include "Vertex.h"

class Bor_Avto
{
	std::vector<Vertex> Bor_vector; //вектор с бором + суффиксные ссылки
	int Get_next_vertex(int, int); //получения индекса следущей вершины бора при поиске шаблонов в тексте
	int Get_suffix_link(int); //получение индекса следующей вершины через суффиксную ссылку
	void Result(std::vector <std::string>&, int, int, std::string, std::vector<std::pair<int, int>>&); //формирует результат поиска шаблона согласно заданию

public:
	Bor_Avto()
	{
		Bor_vector.push_back(Vertex(0, 0));
	}
	~Bor_Avto() = default;

	void Add_p_i_vertexes(std::map<char, int>, int, std::string); //добавление шаблонов в бор
	void Find_p_i_in_text(std::vector <std::string>, std::string, std::map<char, int>, std::vector<std::pair<int, int>>&);//основной метод поиска шаблонов в тексте
};
