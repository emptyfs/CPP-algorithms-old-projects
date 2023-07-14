#pragma once

#include <algorithm>

class ford_fulkerson
{
public:
	int bandwidth_matrix[300][300] = { 0 }; //матрица смежности пропускных способностей ребер вершин
	int prevs[300] = { 0 }; //пути
	bool visited[300] = { 0 }; //список просмотренных вершин
	int flow[300][300] = { 0 }; //фактическая величина потока на ребре
	int istock; //исток
	int stock; //сток

	void initPrevs(); //обнуление путей
	void dfs(int); //поиск путей в глубину
	bool getPath(int); //получение пути
	int alg(); //максимальный поток
};