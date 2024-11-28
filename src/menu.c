#include <stdio.h>
#include <string.h>
#include "operations.h"
#include "history.h"
#include "utils.h"

#define MAX_NUMBERS 100
#define HISTORY_SIZE 10

void run_calculator() {
    int count, choice, history_count = 0;
    float numbers[MAX_NUMBERS], result;
    History history[1000];
    int mat1[10][10], mat2[10][10], mat_result[10][10];
    int rows, cols;

    history_count = load_history_from_csv(history, 1000);

    while (1) {
        printf("\nWhich action do you want to take?\n");
        printf("1. Addition Process\n");
        printf("2. Subtraction Process\n");
        printf("3. Multiplication Process\n");
        printf("4. Division Process\n");
        printf("5. Square Root\n");
        printf("6. Power (x^y)\n");
        printf("7. Matrix Addition\n");
        printf("8. Show History\n");
        printf("9. Exit Menu\n");
        printf("Your Choice: ");
        scanf("%d", &choice);

        if (choice == 9) {
            save_history_to_csv(history, history_count);
            printf("Exiting the program...\n");
            break;
        }

        char process_name[30];
        char transaction_detail[200] = "";

        switch (choice) {
            case 1:
                strcpy(process_name, "Addition Process");
                get_numbers(&count, numbers);
                result = addition_process(count, numbers);
                format_transaction_detail(count, numbers, "+", transaction_detail);
                printf("Addition Result: %.2f\n", result);
                break;
            case 2:
                strcpy(process_name, "Subtraction Process");
                get_numbers(&count, numbers);
                result = subtraction_process(count, numbers);
                format_transaction_detail(count, numbers, "-", transaction_detail);
                printf("Subtraction Result: %.2f\n", result);
                break;
            case 3:
                strcpy(process_name, "Multiplication Process");
                get_numbers(&count, numbers);
                result = multiplication_process(count, numbers);
                format_transaction_detail(count, numbers, "*", transaction_detail);
                printf("Multiplication Result: %.2f\n", result);
                break;
            case 4:
                strcpy(process_name, "Division Process");
                get_numbers(&count, numbers);
                result = division_process(count, numbers);
                format_transaction_detail(count, numbers, "/", transaction_detail);
                printf("Division Result: %.2f\n", result);
                break;
            case 5: {
                strcpy(process_name, "Square Root");
                float number;
                printf("Enter the number for Square Root: ");
                scanf("%f", &number);
                sprintf(transaction_detail, "%.2f", number);
                result = squareroot_process(number);
                printf("Square Root Result: %.2f\n", result);
                count = 1;
                break;
            }
            case 6: {
                strcpy(process_name, "Power Process");
                float base, exponent;
                printf("Enter the base: ");
                scanf("%f", &base);
                printf("Enter the exponent: ");
                scanf("%f", &exponent);
                sprintf(transaction_detail, "%.2f ^ %.2f", base, exponent);
                result = exponent_number_process(base, exponent);
                printf("Power Result: %.2f\n", result);
                count = 2;
                break;
            }
            case 7: {
                strcpy(process_name, "Matrix Addition");

                printf("Enter matrix dimensions (rows and cols): ");
                scanf("%d %d", &rows, &cols);

                printf("Enter elements of the first matrix:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("mat1[%d][%d]: ", i + 1, j + 1);
                        if (scanf("%d", &mat1[i][j]) != 1) {
                            printf("Invalid input! Please enter integers only.\n");
                            j--;
                            while (getchar() != '\n');
                        }
                    }
                }

                printf("Enter elements of the second matrix:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("mat2[%d][%d]: ", i + 1, j + 1);
                        if (scanf("%d", &mat2[i][j]) != 1) {
                            printf("Invalid input! Please enter integers only.\n");
                            j--;
                            while (getchar() != '\n');
                        }
                    }
                }

                if (rows <= 0 || cols <= 0) {
                    printf("Error: Invalid dimensions. Returning to menu.\n");
                    continue;
                }

                matrix_addition(rows, cols, mat1, mat2, mat_result);

                printf("Matrix Addition Result:\n");
                print_matrix(rows, cols, mat_result);

                sprintf(transaction_detail, "Matrix Addition (%dx%d)", rows, cols);
                save_to_history(history, &history_count, process_name, rows * cols, transaction_detail, 0);
                save_history_to_csv(history, history_count);
                break;
            }
            case 8:
                display_paginated_history(history, history_count);
                continue;
            default:
                printf("Invalid choice. Please try again.\n");
                continue;
        }

        if (choice >= 1 && choice <= 6) {
            save_to_history(history, &history_count, process_name, count, transaction_detail, result);
            save_history_to_csv(history, history_count);
        }
    }
}