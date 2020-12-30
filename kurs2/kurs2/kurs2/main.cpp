#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "Header.h"


int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size = 5;
	/*printf("Введите размер матрицы: ");
	scanf("%d", &size);
	char** adj = gen_adj_matrix(size);*/
	char to_adj[5][5] = {
		{0, 9, 75, 0, 0},
		{ 9, 0, 95, 19, 42 },
		{ 75, 95, 0, 51, 66 },
		{ 0, 19, 51, 0, 31 },
		{ 0, 42, 66, 31, 0 }
	};
	char** matrix = (char**)calloc(size, sizeof(char*));
	if (matrix == NULL)
		return NULL;

	for (int i = 0; i < size; i++) {
		matrix[i] = (char*)calloc(size, sizeof(char));
		if (matrix[i] == NULL)
			return NULL;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = to_adj[i][j];
		}
	}
	printf("Матрица смежности: \n");
	pr_adj_matrix(matrix, size);
	printf("\n");
	pr_adj_matrix(Prim(matrix, size), size);
	_getch();
}