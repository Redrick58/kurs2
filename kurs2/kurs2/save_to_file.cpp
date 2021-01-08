#include <stdio.h>


int save_to_file(FILE* fp, char** adj, char** tree, int size) {


	fprintf(fp, "������� ��������� ��������� �����:\n");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			fprintf(fp, "%-4d", adj[i][j]);
		}
		fprintf(fp, "\n");
	}

	fprintf(fp, "\n������� ��������� ������������ ��������� ������:\n");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			fprintf(fp, "%-4d", tree[i][j]);
		}
		fprintf(fp, "\n");
	}
	return 0;
}