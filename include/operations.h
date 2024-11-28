#ifndef OPERATIONS_H
#define OPERATIONS_H

float addition_process(int count, float numbers[]);
float subtraction_process(int count, float numbers[]);
float multiplication_process(int count, float numbers[]);
float division_process(int count, float numbers[]);
float squareroot_process(float x);
float exponent_number_process(float base, float exponent);

void matrix_addition(int rows, int cols, int mat1[10][10], int mat2[10][10], int result[10][10]);
void print_matrix(int rows, int cols, int matrix[10][10]);
void matrix_multiplication(int rows1, int cols1, int mat1[10][10], int rows2, int cols2, int mat2[10][10], int result[10][10]);
int determinant(int matrix[10][10], int n);

#endif