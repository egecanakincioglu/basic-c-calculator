#include "basic_operations.h"
#include "utils.h"
#include "history.h"
#include <string.h>
#include <stdio.h>

void handle_basic_operations(int choice, HistoryNode **history) {
    int count;
    float numbers[MAX_NUMBERS], result;
    char process_name[30];
    char transaction_detail[200];

    switch (choice) {
        case 1:
            strcpy(process_name, "Addition");
            get_numbers(&count, numbers);
            result = addition_process(count, numbers);
            format_transaction_detail(count, numbers, "+", transaction_detail);
            break;
        case 2:
            strcpy(process_name, "Subtraction");
            get_numbers(&count, numbers);
            result = subtraction_process(count, numbers);
            format_transaction_detail(count, numbers, "-", transaction_detail);
            break;
        case 3:
            strcpy(process_name, "Multiplication");
            get_numbers(&count, numbers);
            result = multiplication_process(count, numbers);
            format_transaction_detail(count, numbers, "*", transaction_detail);
            break;
        case 4:
            strcpy(process_name, "Division");
            get_numbers(&count, numbers);
            result = division_process(count, numbers);
            format_transaction_detail(count, numbers, "/", transaction_detail);
            break;
        case 5: {
            strcpy(process_name, "Square Root");
            float number;
            printf("Enter the number to find the square root: ");
            if (scanf("%f", &number) != 1) {
                printf("Error: Invalid input! Please enter a valid number.\n");
                return;
            }
            result = squareroot_process(number);
            sprintf(transaction_detail, "sqrt(%.2f)", number);
            count = 1;
            break;
        }
        case 6: {
            strcpy(process_name, "Power");
            float base, exponent;
            printf("Enter the base: ");
            if (scanf("%f", &base) != 1) {
                printf("Error: Invalid input! Please enter a valid base.\n");
                return;
            }
            printf("Enter the exponent: ");
            if (scanf("%f", &exponent) != 1) {
                printf("Error: Invalid input! Please enter a valid exponent.\n");
                return;
            }
            result = exponent_number_process(base, exponent);
            sprintf(transaction_detail, "%.2f ^ %.2f", base, exponent);
            count = 2;
            break;
        }
    }

    printf("Result: %.2f\n", result);
    save_to_history(history, process_name, count, transaction_detail, result);
}