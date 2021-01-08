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
		printf("1) Задать граф с клавиатуры\n");
		printf("2) Сгенерировать граф\n");
		printf("0) Выход\n\n");

		switch (_getch()) {

		case ('0'): {
			return (0);
		}

		case ('1'): {
			printf("Ввод графа с клавиатуры\n");
			printf("Введите количество вершин: ");
			scanf("%d", &size);
			if (size <= 0) {
				printf("\nМинимальное количество вершин - 1\n");
				size = 1;
			}
			adj = enter_adj(size);
			printf("Матрица смежности исходного графа: \n");
			pr_adj_matrix(adj, size);
			printf("\n");
			printf("Матрица смежности минимального остовного дерева: \n");
			tree = Prim(adj, size);
			pr_adj_matrix(tree, size);
			for (; 1;) {
				savedflag = 0;
				printf("\nСохранить?\n");
				printf("y) Да\n");
				printf("n) Нет\n");
				switch (_getch()) {
				case ('y'): {
					clean_stream();
					printf("Введите имя файла (если существует, будет перезаписан): ");
					gets_s(filename, 255);
					if ((fp = fopen(filename, "w")) == NULL) {
						printf("\nНе удалось открыть файл.\n");
						break;
					}
					else {
						save_to_file(fp, adj, tree, size);
						fclose(fp);
						printf("\nЗаписано успешно!\n");
						savedflag = 1;
						break;
					}
				}
				case ('n'): {
					savedflag = 1;
					break;
				}
				default: {
					printf("\nНеизвестная команда\n");
				}
				}
				if (savedflag) {
					break;
				}
			}
			printf("\nНажмите любую клавишу для продолжения.");
			_getch();
			system("cls");
			break;
		}
		case ('2'): {
			printf("Генерация графа\n");
			printf("Введите количество вершин: ");
			scanf("%d", &size);
			if (size <= 0) {
				printf("\nМинимальное количество вершин - 1\n");
				size = 1;
			}
			adj = gen_adj_matrix(size);
			printf("Матрица смежности исходного графа: \n");
			pr_adj_matrix(adj, size);
			printf("\n");
			printf("Матрица смежности минимального остовного дерева: \n");
			tree = Prim(adj, size);
			pr_adj_matrix(tree, size);
			for (;1;) {
				savedflag = 0;
				printf("\nСохранить?\n");
				printf("y) Да\n");
				printf("n) Нет\n");
				switch (_getch()) {
				case ('y'): {
					clean_stream();
					printf("Введите имя файла (если существует, будет перезаписан): ");
					gets_s(filename, 255);
					if ((fp = fopen(filename, "w")) == NULL) {
						printf("\nНе удалось открыть файл.\n");
						break;
					}
					else {
						save_to_file(fp, adj, tree, size);
						fclose(fp);
						printf("\nЗаписано успешно!\n");
						savedflag = 1;
						break;
					}
				}
				case ('n'): {
					savedflag = 1;
					break;
				}
				default: {
					printf("\nНеизвестная команда\n");
				}
				}
				if (savedflag) {
					break;
				}
			}
			printf("\nНажмите любую клавишу для продолжения.");
			_getch();
			system("cls");
			break;
		}
		default: printf("Неизвестная команда\n\n");
		}
	}
}