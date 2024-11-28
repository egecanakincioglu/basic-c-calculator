#ifndef HISTORY_H
#define HISTORY_H

#define HISTORY_CSV_FILE "./data/history.csv"

typedef struct HistoryNode {
    char process_name[30];
    int transaction_size;
    char transaction_detail[200];
    float result;
    struct HistoryNode *next;
} HistoryNode;

void add_to_history(HistoryNode **head, char *process_name, int transaction_size, char *transaction_detail, float result);
void display_history(HistoryNode *head);
void clear_history(HistoryNode **head);
void save_history_to_csv(HistoryNode *head);
void load_history_from_csv(HistoryNode **head);
void save_to_history(HistoryNode **head, char *process_name, int transaction_size, char *transaction_detail, float result);
void display_paginated_history(HistoryNode *head);

#endif