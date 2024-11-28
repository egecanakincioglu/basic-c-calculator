#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include "history.h"

void handle_matrix_operations(int choice, HistoryNode **history);
void matrix_addition(int rows, int cols, int mat1[10][10], int mat2[10][10], int result[10][10]);
void matrix_multiplication(int rows1, int cols1, int mat1[10][10], int rows2, int cols2, int mat2[10][10], int result[10][10]);
int determinant(int matrix[10][10], int n);
void print_matrix(int rows, int cols, int matrix[10][10]);
void read_matrix(int rows, int cols, int matrix[10][10]);

#endif