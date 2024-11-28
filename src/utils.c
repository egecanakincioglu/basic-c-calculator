#include <stdio.h>
#include <string.h>
#include "utils.h"

void get_numbers(int *count, float numbers[]) {
    printf("How many numbers will you enter? ");
    if (scanf("%d", count) != 1 || *count <= 0) {
        printf("Incorrect login! Enter a valid positive integer.\n");
        while (getchar() != '\n');
        *count = 0;
        return;
    }

    for (int i = 0; i < *count; i++) {
        printf("Number %d: ", i + 1);
        if (scanf("%f", &numbers[i]) != 1) {
            printf("Incorrect login! Enter a valid number.\n");
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