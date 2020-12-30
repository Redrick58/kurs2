#include <stdlib.h>
#include <stdio.h>

void DFS(char** matrix, int v, char* visited, int size) {

	visited[v] = 1;
	//printf("%d ", v);
	for (int i = 0; i < size; i++) {
		if ((visited[i] == 0) && (matrix[v][i]))
		{
			DFS(matrix, i, visited, size);
		}
	}
}

int POG(char** matrix, int size) {

	int connum = 0;
	char* visited = (char*)calloc(size, sizeof(char));
	for (int i = 0; i < size; i++) {
		visited[i] = 0;
	}
	for (int v = 0; v < size; v++)
	{
		if (visited[v] == 0) {
			DFS(matrix, v, visited, size);
			connum++;
		}
		//printf("\n");
	}
	return connum;
}

