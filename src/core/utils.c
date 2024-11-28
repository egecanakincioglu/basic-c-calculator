#include "utils.h"
#include <stdio.h>
#include <string.h>

void get_numbers(int *count, float numbers[]) {
    printf("How many numbers will you enter? ");
    if (scanf("%d", count) != 1 || *count <= 0) {
        printf("Incorrect input! Enter a valid positive integer.\n");
        while (getchar() != '\n');
        *count = 0;
        return;
    }

    for (int i = 0; i < *count; i++) {
        printf("Number %d: ", i + 1);
        if (scanf("%f", &numbers[i]) != 1) {
            printf("Incorrect input! Enter a valid number.\n");
            while (getchar() != '\n');
            i--;
        }
    }
}

void format_transaction_detail(int count, float numbers[], const char *operator, char *transaction_detail) {
    transaction_detail[0] = '\0';
    for (int i = 0; i < count; i++) {
        char temp[20];
        sprintf(temp, "%.2f", numbers[i]);
        strcat(transaction_detail, temp);
        if (i < count - 1) {
            strcat(transaction_detail, " ");
            strcat(transaction_detail, operator);
            strcat(transaction_detail, " ");
        }
    }
}

void read_matrix(int rows, int cols, int matrix[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
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