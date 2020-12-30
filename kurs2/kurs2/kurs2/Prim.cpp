#include <stdlib.h>
#include "Header.h"

int get_min_adj(int vertex, char** matrix, int size, char* visited) {

	int vertex2 = -1;
	int min = 0;
	for (int j = 0; j < size; j++) {
		if (visited[j] == 0) {
			if (min == 0) {
				min = matrix[vertex][j];
				vertex2 = j;
			}
			else if (matrix[vertex][j] < min) {
				min = matrix[vertex][j];
				vertex2 = j;
			}
		}
	}
	return vertex2;
}

char** Prim(char** matrix, int size) {

	int vertex2;

	char** ostov = (char**)calloc(size, sizeof(char*));
	if (ostov == NULL)
		return NULL;

	for (int i = 0; i < size + 1; i++) {
		ostov[i] = (char*)calloc(size, sizeof(char));
		if (ostov[i] == NULL)
			return NULL;
	}

	char* visited = (char*)calloc(size, sizeof(char));
	if (visited == NULL)
		return NULL;

	for (int i = 0; i < size; i++) {
		visited[i] = 0;
	}

	visited[0] = 1;

	for (int edge = 0; edge < size - 1; edge++) {
		for (int i = 0; i < size; i++) {
			if (visited[i]) {
				vertex2 = get_min_adj(i, matrix, size, visited);
				if (vertex2 != -1) {
					ostov[i][vertex2] = matrix[i][vertex2];
					ostov[vertex2][i] = matrix[i][vertex2];
				}
			}
		}
		visited[vertex2] = 1;
	}
	return ostov;
}