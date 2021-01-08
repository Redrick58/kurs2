#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <stdio.h>
#include <stdlib.h>

char** enter_adj(int size) {

	int flag = 1;
	char** matrix = (char**)calloc(size, sizeof(char*));
	if (matrix == NULL)
		return NULL;

	for (int i = 0; i < size; i++) {
		matrix[i] = (char*)calloc(size, sizeof(char));
		if (matrix[i] == NULL)
			return NULL;
	}

	do {
		if (flag != 1) {
			printf("Граф несвязный! Введите связный граф.\n");
		}
		for (int i = 0; i < size; i++) {
			for (int j = i; j < size; j++) {
				printf("Введите длину ребра %d - %d (введите 0 если нет ребра): ", i, j);
				scanf("%d", &matrix[i][j]);
				matrix[j][i] = matrix[i][j];
			}
		}
		flag = POG(matrix, size);
	} while (flag != 1); //пока не введут связный граф

	return matrix;
}