#include <stdlib.h>
#include "Header.h"


char** Prim(char** matrix, int size) {

	int vertex1;
	int vertex2;
	int min = 0;

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
		vertex1 = -1;
		vertex2 = -1;
		min = 0;
		for (int i = 0; i < size; i++) {
			if (visited[i]) {
				for (int j = 0; j < size; j++) {
					if ((visited[j] == 0) && (matrix[i][j] != 0)) {
						if (min == 0) {
							min = matrix[i][j];
							vertex1 = i;
							vertex2 = j;
						}
						else if (matrix[i][j] < min) {
							min = matrix[i][j];
							vertex1 = i;
							vertex2 = j;
						}
					}
				}
			}
		}
		ostov[vertex2][vertex1] = matrix[vertex1][vertex2];
		ostov[vertex1][vertex2] = matrix[vertex1][vertex2];
		visited[vertex2] = 1;
	}
	return ostov;
}