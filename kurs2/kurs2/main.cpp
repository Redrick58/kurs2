#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "Header.h"

void clean_stream() {
	while (fgetc(stdin) != '\n');
}

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char** adj;
	char** tree;
	int size;
	FILE* fp;
	char filename[256];
	char savedflag = 0;

	for (;1;) {
		printf("1) ������ ���� � ����������\n");
		printf("2) ������������� ����\n");
		printf("0) �����\n\n");

		switch (_getch()) {

		case ('0'): {
			return (0);
		}

		case ('1'): {
			printf("���� ����� � ����������\n");
			printf("������� ���������� ������: ");
			scanf("%d", &size);
			if (size <= 0) {
				printf("\n����������� ���������� ������ - 1\n");
				size = 1;
			}
			adj = enter_adj(size);
			printf("������� ��������� ��������� �����: \n");
			pr_adj_matrix(adj, size);
			printf("\n");
			printf("������� ��������� ������������ ��������� ������: \n");
			tree = Prim(adj, size);
			pr_adj_matrix(tree, size);
			for (; 1;) {
				savedflag = 0;
				printf("\n���������?\n");
				printf("y) ��\n");
				printf("n) ���\n");
				switch (_getch()) {
				case ('y'): {
					clean_stream();
					printf("������� ��� ����� (���� ����������, ����� �����������): ");
					gets_s(filename, 255);
					if ((fp = fopen(filename, "w")) == NULL) {
						printf("\n�� ������� ������� ����.\n");
						break;
					}
					else {
						save_to_file(fp, adj, tree, size);
						fclose(fp);
						printf("\n�������� �������!\n");
						savedflag = 1;
						break;
					}
				}
				case ('n'): {
					savedflag = 1;
					break;
				}
				default: {
					printf("\n����������� �������\n");
				}
				}
				if (savedflag) {
					break;
				}
			}
			printf("\n������� ����� ������� ��� �����������.");
			_getch();
			system("cls");
			break;
		}
		case ('2'): {
			printf("��������� �����\n");
			printf("������� ���������� ������: ");
			scanf("%d", &size);
			if (size <= 0) {
				printf("\n����������� ���������� ������ - 1\n");
				size = 1;
			}
			adj = gen_adj_matrix(size);
			printf("������� ��������� ��������� �����: \n");
			pr_adj_matrix(adj, size);
			printf("\n");
			printf("������� ��������� ������������ ��������� ������: \n");
			tree = Prim(adj, size);
			pr_adj_matrix(tree, size);
			for (;1;) {
				savedflag = 0;
				printf("\n���������?\n");
				printf("y) ��\n");
				printf("n) ���\n");
				switch (_getch()) {
				case ('y'): {
					clean_stream();
					printf("������� ��� ����� (���� ����������, ����� �����������): ");
					gets_s(filename, 255);
					if ((fp = fopen(filename, "w")) == NULL) {
						printf("\n�� ������� ������� ����.\n");
						break;
					}
					else {
						save_to_file(fp, adj, tree, size);
						fclose(fp);
						printf("\n�������� �������!\n");
						savedflag = 1;
						break;
					}
				}
				case ('n'): {
					savedflag = 1;
					break;
				}
				default: {
					printf("\n����������� �������\n");
				}
				}
				if (savedflag) {
					break;
				}
			}
			printf("\n������� ����� ������� ��� �����������.");
			_getch();
			system("cls");
			break;
		}
		default: printf("����������� �������\n\n");
		}
	}
}