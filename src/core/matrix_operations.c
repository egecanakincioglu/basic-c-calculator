#include "matrix_operations.h"
#include "utils.h"
#include "history.h"
#include <string.h>
#include <stdio.h>

void handle_matrix_operations(int choice, HistoryNode **history) {
    int rows, cols, rows1, cols1, rows2, cols2;
    int mat1[10][10], mat2[10][10], mat_result[10][10];
    char process_name[30];
    char transaction_detail[200];

    if (choice == 7) {
        strcpy(process_name, "Matrix Addition");
        printf("Enter dimensions (rows cols): ");
        scanf("%d %d", &rows, &cols);
        printf("Enter first matrix:\n");
        read_matrix(rows, cols, mat1);
        printf("Enter second matrix:\n");
        read_matrix(rows, cols, mat2);
        matrix_addition(rows, cols, mat1, mat2, mat_result);
        sprintf(transaction_detail, "Matrix Addition (%dx%d)", rows, cols);
        print_matrix(rows, cols, mat_result);
        save_to_history(history, process_name, rows * cols, transaction_detail, 0);
    } else if (choice == 8) {
        strcpy(process_name, "Matrix Multiplication");
        printf("Enter dimensions of first matrix (rows cols): ");
        scanf("%d %d", &rows1, &cols1);
        printf("Enter dimensions of second matrix (rows cols): ");
        scanf("%d %d", &rows2, &cols2);

        if (cols1 != rows2) {
            printf("Error: Invalid dimensions for multiplication.\n");
            return;
        }

        printf("Enter first matrix:\n");
        read_matrix(rows1, cols1, mat1);
        printf("Enter second matrix:\n");
        read_matrix(rows2, cols2, mat2);
        matrix_multiplication(rows1, cols1, mat1, rows2, cols2, mat2, mat_result);
        sprintf(transaction_detail, "Matrix Multiplication (%dx%d)x(%dx%d)", rows1, cols1, rows2, cols2);
        print_matrix(rows1, cols2, mat_result);
        save_to_history(history, process_name, rows1 * cols2, transaction_detail, 0);
    } else if (choice == 9) {
        strcpy(process_name, "Determinant Calculation");
        printf("Enter dimension of square matrix: ");
        scanf("%d", &rows);
        if (rows <= 0 || rows > 10) {
            printf("Error: Invalid dimension.\n");
            return;
        }
        printf("Enter matrix:\n");
        read_matrix(rows, rows, mat1);
        int det = determinant(mat1, rows);
        printf("Determinant: %d\n", det);
        sprintf(transaction_detail, "Determinant (%dx%d)", rows, rows);
        save_to_history(history, process_name, rows * rows, transaction_detail, det);
    }
}