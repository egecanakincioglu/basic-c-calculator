#ifndef BASIC_OPERATIONS_H
#define BASIC_OPERATIONS_H

#include "history.h"

float addition_process(int count, float numbers[]);
float subtraction_process(int count, float numbers[]);
float multiplication_process(int count, float numbers[]);
float division_process(int count, float numbers[]);
float squareroot_process(float x);
float exponent_number_process(float base, float exponent);

void handle_basic_operations(int choice, HistoryNode **history);

#endif