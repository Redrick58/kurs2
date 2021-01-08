#include <stdio.h>


int pr_adj_matrix(char** matrix, int size) {

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%-4d", matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}