#ifndef HISTORY_H
#define HISTORY_H

#define CSV_FILE "./data/history.csv"
#define HISTORY_SIZE 10

typedef struct {
    char process_name[30];
    int transaction_size;
    char transaction_detail[200];
    float result;
} History;

void save_history_to_csv(History history[], int history_count);
int load_history_from_csv(History history[], int max_count);
void save_to_history(History history[], int *history_count, char *process_name, int transaction_size, char *transaction_detail, float result);
void display_paginated_history(History history[], int total_count);

#endif