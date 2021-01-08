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
			printf("���� ���������! ������� ������� ����.\n");
		}
		for (int i = 0; i < size; i++) {
			for (int j = i; j < size; j++) {
				printf("������� ����� ����� %d - %d (������� 0 ���� ��� �����): ", i, j);
				scanf("%d", &matrix[i][j]);
				matrix[j][i] = matrix[i][j];
			}
		}
		flag = POG(matrix, size);
	} while (flag != 1); //���� �� ������ ������� ����

	return matrix;
}