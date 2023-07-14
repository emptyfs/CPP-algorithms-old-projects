#include "Vertex.h"

Vertex::Vertex(int parent, char symbol) : parent(parent), edge_symbol(symbol)
{
	for (int i = 0; i < 5; i++)
	{
		child[i] = -1;
		way[i] = -1;
	}
	str_number.resize(0);
}
Vertex::Vertex() = default;
