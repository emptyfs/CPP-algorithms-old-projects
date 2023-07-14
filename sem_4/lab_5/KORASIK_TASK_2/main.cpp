#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <sstream>
#include "Vertex.h"
#include "Bor_Avto.h"

int main() 
{
	std::string text; //текст
	std::string P; //шаблон
	char joker; //джокер

	std::map<char, int> alphabet{ {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}, {'N', 4} }; //объявляется алфавит (символы, которые встречаются в переданных тексте и шаблонах, каждому из них ставится в соответсвие определенный уникальный номер)
	Bor_Avto Bor;

	std::cin >> text >> P >> joker;

	std::stringstream str_stream(P);
	std::vector<int> templates_length = Bor.Templates(alphabet, str_stream, joker);
	std::vector<int> additional_array(text.size(), 0);

	Bor.Find_p_i_in_text(alphabet, text, additional_array, templates_length);
	Bor.Result_print(additional_array, text.size(), P.size());

	return 0;
}