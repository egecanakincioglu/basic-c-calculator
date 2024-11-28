#ifndef UTILS_H
#define UTILS_H

#define MAX_NUMBERS 100

void get_numbers(int *count, float numbers[]);
void format_transaction_detail(int count, float numbers[], const char *operator, char *transaction_detail);

#endif