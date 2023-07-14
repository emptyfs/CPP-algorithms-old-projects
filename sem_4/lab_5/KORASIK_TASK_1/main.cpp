#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
#include <vector>
#include "Vertex.h"
#include "Bor_Avto.h"

int main()
{
	std::string text; // текст
	int N; // количество шаблонов
	std::string P_I; // i-ый шаблон
	std::vector<std::string> vector_P_I; // вектор шаблонов
	std::vector<std::pair<int, int>> output; //вектор для вывода

	std::map<char, int> alphabet{ {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}, {'N', 4} }; //объявляется алфавит (символы, которые встречаются в переданных тексте и шаблонах, каждому из них ставится в соответсвие определенный уникальный номер)
	Bor_Avto Bor;

	std::cin >> text >> N;

	for (int i = 0; i < N; i++) //создание бора и заполнение vector_P_I переданными шаблонами
	{
		std::cin >> P_I;
		Bor.Add_p_i_vertexes(alphabet, i, P_I);
		vector_P_I.push_back(P_I);
	}

	Bor.Find_p_i_in_text(vector_P_I, text, alphabet, output);

	sort(output.begin(), output.end()); //сортировка ouput для вывода согласно заданию

	for (int i = 0; i < output.size(); i++)
	{
		std::cout << output[i].first << ' ' << output[i].second << '\n';
	}

	return 0;
}