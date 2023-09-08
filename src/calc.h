#ifndef CALC
#define CALC

#include <math.h>
#include <stdio.h>

#include "parcing.h"
#include "poll_notation.h"

double calc_result(Stack* Stack, int curr);
int is_digit(char* ch);
char* is_X(char* ch, int curr);

#endif