#include "ford_fulkerson.h"

void ford_fulkerson::initPrevs()
{
	for (int i = 0; i < 300; i++)
	{
		prevs[i] = -1;
	}
}

void ford_fulkerson::dfs(int v)
{
	visited[v] = true; //пометка, что пройденная вершина просмотренна
	for (int i = 0; i < 300; i++)
	{
		if (!visited[i] && (bandwidth_matrix[v][i] - flow[v][i] > 0 && bandwidth_matrix[v][i] != 0 || flow[v][i] < 0 && bandwidth_matrix[i][v] != 0)) //(если вершина не просмотрена + остаточный поток больше нуля на ребре + пропускная способность на ребре не равна нулю) или (фактическая величина потока на ребре меньше нуля + пропускная способность не равна нулю)
		{
			prevs[i] = v; //запоминаем путь
			dfs(i);
		}
	}
}

bool ford_fulkerson::getPath(int v) //ищем путь до стока по dfs
{
	dfs(v);
	for (int i = 0; i < 300; i++)
	{
		visited[i] = false; //обнуление посещенных вершин
	}
	return (prevs[stock] != -1);
}

int ford_fulkerson::alg()
{
	int maxFlow = 0; //максимальный поток
	while (getPath(istock)) //пока не дошли до конца сток
	{
		int tmp = 10000000; //текущая минимальная пропускная способность
		for (int v = stock; 0 <= prevs[v]; v = prevs[v]) //проход по найденному пути
		{
			tmp = std::min(tmp, bandwidth_matrix[prevs[v]][v] - flow[prevs[v]][v]); //минимальная пропускная способность
		}
		for (int v = stock; 0 <= prevs[v]; v = prevs[v])
		{
			flow[prevs[v]][v] += tmp; //увеличение "обратного" пути ребра на tmp
			flow[v][prevs[v]] -= tmp;; //уменьшение "прямого" пути ребра на tmp
		}
		maxFlow += tmp; //увеличение максимального потока на tmp
		initPrevs();
	}
	return maxFlow;
}