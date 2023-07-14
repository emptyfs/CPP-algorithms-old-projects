#pragma once

#include <vector>
#include "Vertex.h"
#include <map>
#include <sstream>
#include <iostream>

class Bor_Avto
{
	std::vector<Vertex> Bor_vector; //вектор с бором + суффиксные ссылки
	int Get_next_vertex(int, int); //получения индекса следущей вершины бора при поиске шаблонов в тексте
	int Get_suffix_link(int); //получение индекса следующей вершины через суффиксную ссылку
	void Result(int, int, std::vector <int>&, std::vector<int>);
	std::vector<std::string> template_strings; //вектор строк
	void Add_p_i_vertexes(std::map<char, int>, std::string); //добавление строки в бор

public:
	Bor_Avto()
	{
		Bor_vector.push_back(Vertex(0, 0));
	}
	~Bor_Avto() = default;

	void Find_p_i_in_text(std::map<char, int>, std::string&, std::vector <int>&, const std::vector <int>&);
	std::vector <int> Templates(std::map<char, int>, std::stringstream&, char);
	void Result_print(const std::vector<int>&, int, int);
};
