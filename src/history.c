#include <stdio.h>
#include <string.h>
#include "history.h"

void save_history_to_csv(History history[], int history_count) {
    FILE *file = fopen(CSV_FILE, "w");
    if (file == NULL) {
        printf("Error: Unable to open file for saving history.\n");
        return;
    }
    for (int i = 0; i < history_count; i++) {
        fprintf(file, "%s,%d,%s,%.2f\n", history[i].process_name, history[i].transaction_size,
                history[i].transaction_detail, history[i].result);
    }
    fclose(file);
}

int load_history_from_csv(History history[], int max_count) {
    FILE *file = fopen(CSV_FILE, "r");
    if (file == NULL) {
        printf("No history file found. Starting fresh.\n");
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%[^,],%d,%[^,],%f\n", history[count].process_name,
                  &history[count].transaction_size, history[count].transaction_detail,
                  &history[count].result) != EOF) {
        count++;
        if (count >= max_count) break;
    }
    fclose(file);
    return count;
}

void display_paginated_history(History history[], int total_count) {
    int page = 0;
    int items_per_page = HISTORY_SIZE;

    while (1) {
        int start = page * items_per_page;
        int end = start + items_per_page;
        if (end > total_count) end = total_count;

        printf("\n+-------------------------+--------------------+--------------------------------+------------+\n");
        printf("| PROCESS                 | TRANSACTION SIZE   | TRANSACTION DETAIL             | RESULT     |\n");
        printf("+-------------------------+--------------------+--------------------------------+------------+\n");
        for (int i = start; i < end; i++) {
            printf("| %-23s | %-18d | %-30s | %-10.2f |\n", history[i].process_name,
                   history[i].transaction_size, history[i].transaction_detail, history[i].result);
        }
        printf("+-------------------------+--------------------+--------------------------------+------------+\n");

        printf("\nPage %d/%d\n", page + 1, (total_count + items_per_page - 1) / items_per_page);
        printf("Options:\n");
        printf("1. Next Page\n");
        printf("2. Previous Page\n");
        printf("3. Back to Menu\n");
        printf("Your Choice: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1 && end < total_count) {
            page++;
        } else if (choice == 2 && page > 0) {
            page--;
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }
}

void save_to_history(History history[], int *history_count, char *process_name, int transaction_size, char *transaction_detail, float result) {
    strcpy(history[*history_count].process_name, process_name);
    history[*history_count].transaction_size = transaction_size;
    strcpy(history[*history_count].transaction_detail, transaction_detail);
    history[*history_count].result = result;
    (*history_count)++;
}