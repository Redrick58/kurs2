#pragma once
#include <stdio.h>

int pr_adj_matrix(char** matrix, int size);
char** gen_adj_matrix(int size);
int POG(char** matrix, int size);
char** Prim(char** matrix, int size);
char** enter_adj(int size);
int save_to_file(FILE* fp, char** adj, char** tree, int size);