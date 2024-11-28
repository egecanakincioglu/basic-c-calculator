#include <stdio.h>
#include <math.h>
#include "operations.h"

float addition_process(int count, float numbers[]) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    return sum;
}

float subtraction_process(int count, float numbers[]) {
    float result = numbers[0];
    for (int i = 1; i < count; i++) {
        result -= numbers[i];
    }
    return result;
}

float multiplication_process(int count, float numbers[]) {
    float product = 1;
    for (int i = 0; i < count; i++) {
        product *= numbers[i];
    }
    return product;
}

float division_process(int count, float numbers[]) {
    float result = numbers[0];
    for (int i = 1; i < count; i++) {
        if (numbers[i] == 0) {
            printf("Error: Dividing by zero is not possible! \n");
            return 0;            
        }
        result /= numbers[i];
    }
    return result;
}

float squareroot_process(float x) {
    if (x < 0) {
        printf("Error: You cannot take the square root of a negative number!\n");
        return 0;
    }
    return sqrt(x);
}

float exponent_number_process(float base, float exponent) {
    return pow(base, exponent);
}

void matrix_addition(int rows, int cols, int mat1[10][10], int mat2[10][10], int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void print_matrix(int rows, int cols, int matrix[10][10]) {
    printf("\nMatrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}