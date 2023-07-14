#include "Bor_Avto.h"

void Bor_Avto::Add_p_i_vertexes(std::map<char, int> alphabet, std::string str)
{
	int n = 0; //номер вершины в боре

	for (int i = 0; i < str.size(); i++) {
		char symbol = str[i]; //в symbol кладется i-ый символ из переданной строки
		int s_edge = alphabet[symbol]; //в s_edge кладется номер этого символа согласно алфавиту
		if (Bor_vector[n].child[s_edge] == -1) //если у текущей вершины бора нет потомка с номер s_edge (s_edge соотвествует символу алфавита), то
		{
			Bor_vector.push_back(Vertex(n, s_edge)); //кладем в бор-вектор вершину с родителем 'n' (текущая вершина) и символом, которых их соединяет - s_edge
			Bor_vector[n].child[s_edge] = Bor_vector.size() - 1; //в массиве потомков для текущего вектора отмечается, что потомок стоит на <текущая длина бор-вектора - 1> месте в бор-векторе
		}
		n = Bor_vector[n].child[s_edge]; //в n кладется индекс потомка в бор-векторе
	}
	Bor_vector[n].flag = true; //последняя вершина (к которой ведет ребро с последний символом из переданной строки p_i) помечается терминальной
	template_strings.push_back(str); //добавление этой строки в вектор строк
	Bor_vector[n].str_number.push_back(template_strings.size() - 1); //отметка этой строки в боре

}

int Bor_Avto::Get_suffix_link(int vertex_index)
{
	if (Bor_vector[vertex_index].suffix_link == -1) //если суффикусной ссылки нет
	{
		if (vertex_index == 0 || Bor_vector[vertex_index].parent == 0) //если это пустая вершина или ее потомки
		{
			Bor_vector[vertex_index].suffix_link = 0; //отмечаем суффиксную ссылку дли них (на пустую вершину)
		}
		else //если это не пустая вершина
		{
			Bor_vector[vertex_index].suffix_link = Get_next_vertex(Get_suffix_link(Bor_vector[vertex_index].parent), Bor_vector[vertex_index].edge_symbol); //поиск суффиксной ссылки через предка 
		} //этот метод будет запускаться для вершин, у которых родитель не пустой, для пустого родителя будет запускаться только get_suffix_link
	}
	return Bor_vector[vertex_index].suffix_link;
}

int Bor_Avto::Get_next_vertex(int vertex_index, int symbol_on_edge)
{
	if (Bor_vector[vertex_index].way[symbol_on_edge] == -1) //если путь для переданной вершины до вершины с ребром текущего символа не отмечен
	{
		if (Bor_vector[vertex_index].child[symbol_on_edge] != -1) //если для переданной вершины есть вершина-ребенок с текущим символом
		{
			Bor_vector[vertex_index].way[symbol_on_edge] = Bor_vector[vertex_index].child[symbol_on_edge]; //отметка пути (для текущей вершины отмечается путь до вершины-ребенка с ребром текущего символа)
		}
		else //если для переданной вершины нет вершины-ребенока с текущим символом
		{
			if (vertex_index == 0) //если это пустая вершина (корень)
			{
				Bor_vector[vertex_index].way[symbol_on_edge] = 0; //отметка пути (для текущей вершины отмечается, что пути до вершины с ребром текущего символа в боре нет, т.е. из пустой вершины тогда идет путь до нее самой же)
			}
			else //если это не пустая вершина (не корень)
			{
				Bor_vector[vertex_index].way[symbol_on_edge] = Get_next_vertex(Get_suffix_link(vertex_index), symbol_on_edge);
			}
		}
	}
	return Bor_vector[vertex_index].way[symbol_on_edge];
}

void Bor_Avto::Result(int vertex_index, int i, std::vector<int>& additional_array, std::vector<int> templates_length)
{
	for (int u = vertex_index; u != 0; u = Get_suffix_link(u)) //проход от текущей вершины по всем суффикс-ссылкам
	{
		if (Bor_vector[u].flag) //если текущая вершина терминальная
		{
			for (const auto& j : Bor_vector[u].str_number)
			{
				if ((i - templates_length[j] < additional_array.size()))
				{
					additional_array[i - templates_length[j]]++;
				}
			}
		}
	}
}

std::vector<int> Bor_Avto::Templates(std::map<char, int> alphabet, std::stringstream& template_string, char joker)
{
	std::vector<int> templates_length;
	int length = 0;
	std::string storage;
	while (getline(template_string, storage, joker))
	{
		if (storage.size() > 0)
		{
			length += storage.size();
			templates_length.push_back(length);
			Add_p_i_vertexes(alphabet, storage);
		}
		length++;
	}
	return templates_length;
}

void Bor_Avto::Result_print(const std::vector<int>& additional_array, int text_size, int length)
{
	for (int i = 0; i < text_size; i++)
	{
		if ((additional_array[i] == template_strings.size()) && (i + length <= text_size))
		{
			std::cout << i + 1 << "\n";
		}
	}
}

void Bor_Avto::Find_p_i_in_text(std::map<char, int> alphabet, std::string& text, std::vector <int>& additional_array, const std::vector <int>& templates_length)
{
	int u = 0;
	int lenght = text.length();

	for (int i = 0; i < lenght; i++)
	{
		char symbol = text[i]; //i-ый символ из переданного текста
		int s_edge = alphabet[symbol]; //номер этого символа согласно алфавиту
		u = Get_next_vertex(u, s_edge);
		Result(u, i + 1, additional_array, templates_length);
	}
}