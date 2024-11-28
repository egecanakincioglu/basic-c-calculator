#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"

void add_to_history(HistoryNode **head, char *process_name, int transaction_size, char *transaction_detail, float result) {
    HistoryNode *new_node = (HistoryNode *)malloc(sizeof(HistoryNode));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed!\n");
        return;
    }

    strcpy(new_node->process_name, process_name);
    new_node->transaction_size = transaction_size;
    strcpy(new_node->transaction_detail, transaction_detail);
    new_node->result = result;

    new_node->next = *head;
    *head = new_node;
}

void display_history(HistoryNode *head) {
    if (head == NULL) {
        printf("No history available.\n");
        return;
    }

    HistoryNode *current = head;

    printf("\nTransaction History:\n");
    printf("+-------------------------+--------------------+--------------------------------+------------+\n");
    printf("| PROCESS                 | TRANSACTION SIZE   | TRANSACTION DETAIL             | RESULT     |\n");
    printf("+-------------------------+--------------------+--------------------------------+------------+\n");

    while (current != NULL) {
        printf("| %-23s | %-18d | %-30s | %-10.2f |\n",
               current->process_name, current->transaction_size, current->transaction_detail, current->result);
        current = current->next;
    }

    printf("+-------------------------+--------------------+--------------------------------+------------+\n");
}

void clear_history(HistoryNode **head) {
    HistoryNode *current = *head;

    while (current != NULL) {
        HistoryNode *temp = current;
        current = current->next;
        free(temp);
    }

    *head = NULL;
}

void save_history_to_csv(HistoryNode *head) {
    FILE *file = fopen(HISTORY_CSV_FILE, "w");
    if (file == NULL) {
        printf("Error: Unable to open file for saving history.\n");
        return;
    }

    HistoryNode *current = head;
    while (current != NULL) {
        fprintf(file, "%s,%d,%s,%.2f\n",
                current->process_name,
                current->transaction_size,
                current->transaction_detail,
                current->result);
        current = current->next;
    }

    fclose(file);
}

void load_history_from_csv(HistoryNode **head) {
    FILE *file = fopen(HISTORY_CSV_FILE, "r");
    if (file == NULL) {
        printf("No history file found. Starting fresh.\n");
        return;
    }

    char process_name[30];
    int transaction_size;
    char transaction_detail[200];
    float result;

    while (fscanf(file, "%[^,],%d,%[^,],%f\n", process_name, &transaction_size, transaction_detail, &result) != EOF) {
        add_to_history(head, process_name, transaction_size, transaction_detail, result);
    }

    fclose(file);
}

void save_to_history(HistoryNode **head, char *process_name, int transaction_size, char *transaction_detail, float result) {
    add_to_history(head, process_name, transaction_size, transaction_detail, result);
}

void display_paginated_history(HistoryNode *head) {
    display_history(head);
}