#include <iostream>
#include "..\ford_fulkerson.h"

int main() 
{
	int N; //число поданных на вход дуг
	int cost = 0;
	char left; //левая вершина
	char rigth; //правая вершина

	std::cin >> N;
	std::cin >> left >> rigth;

	ford_fulkerson test;
	test.initPrevs();
	test.istock = left - '0';
	test.stock = rigth - '0';

	for (int k = 0; k < N; k++) 
	{
		std::cin >> left >> rigth >> cost;
		int i = left - '0'; //перевод в int
		int j = rigth - '0'; //перевод в int
		test.bandwidth_matrix[i][j] = cost; //обнуление всех потоков сети (в матрице смежности все пути будут равны 0
	}
		
	std::cout << test.alg() << '\n';

	for (int i = 0; i < 300; i++) //вывод фактических величин в потоке
	{
		for (int j = 0; j < 300; j++) {
			if (test.flow[i][j] != 0 && test.flow[i][j] < 0)
			{
				test.flow[i][j] = 0;
			}
			if (test.bandwidth_matrix[i][j] > 0)
			{
				std::cout << (char)(i + '0') << " " << (char)(j + '0') << " " << test.flow[i][j] << '\n';
			}
		}
	}
	return 0;
}