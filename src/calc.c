#include "calc.h"

double calc_result(Stack* tmp_stack, int curr) {
    Stack stack = NULL;
    double result = 0;
    while (*tmp_stack != NULL) {
        char* c = pop(tmp_stack);
        c = is_X(c, curr);
        if (is_digit(c) == 1) {
            push(&stack, c);
        } else {
            if (strcmp(c, "+") == 0) {
                char *a, *b;
                a = pop(&stack);
                b = pop(&stack);
                result = strtod(a, NULL) + strtod(b, NULL);
                free(a);
                free(b);
                char result_str[20];
                sprintf(result_str, "%lf", result);
                push(&stack, result_str);
            } else if (strcmp(c, "-") == 0) {
                char *a, *b;
                a = pop(&stack);
                b = pop(&stack);
                result = strtod(a, NULL) - strtod(b, NULL);
                free(a);
                free(b);
                char result_str[20];
                sprintf(result_str, "%lf", result);
                push(&stack, result_str);
            } else if (strcmp(c, "*") == 0) {
                char *a, *b;
                a = pop(&stack);
                b = pop(&stack);
                result = strtod(a, NULL) * strtod(b, NULL);
                free(a);
                free(b);
                char result_str[20];
                sprintf(result_str, "%lf", result);
                push(&stack, result_str);
            } else if (strcmp(c, "/") == 0) {
                char *a, *b;
                a = pop(&stack);
                b = pop(&stack);
                result = strtod(a, NULL) / strtod(b, NULL);
                free(a);
                free(b);
                char result_str[20];
                sprintf(result_str, "%lf", result);
                push(&stack, result_str);
            } else if (strcmp(c, "sin") == 0) {
                char* a;
                a = pop(&stack);
                result = sin(strtod(a, NULL));
                free(a);
                char result_str[20];
                sprintf(result_str, "%lf", result);
                push(&stack, result_str);
            } else if (strcmp(c, "cos") == 0) {
                char* a;
                a = pop(&stack);
                result = cos(strtod(a, NULL));
                free(a);
                char result_str[20];
                sprintf(result_str, "%lf", result);
                push(&stack, result_str);
            } else if (strcmp(c, "tan") == 0) {
                char* a;
                a = pop(&stack);
                result = tan(strtod(a, NULL));
                free(a);
                char result_str[20];
                sprintf(result_str, "%lf", result);
                push(&stack, result_str);
            } else if (strcmp(c, "ctg") == 0) {
                char* a;
                a = pop(&stack);
                result = 1 / tan(strtod(a, NULL));
                free(a);
                char result_str[20];
                sprintf(result_str, "%lf", result);
                push(&stack, result_str);
            } else if (strcmp(c, "sqrt") == 0) {
                char* a;
                a = pop(&stack);
                result = sqrt(strtod(a, NULL));
                free(a);
                char result_str[20];
                sprintf(result_str, "%lf", result);
                push(&stack, result_str);
            } else if (strcmp(c, "ln") == 0) {
                char* a;
                a = pop(&stack);
                result = log(strtod(a, NULL));
                free(a);
                char result_str[20];
                sprintf(result_str, "%lf", result);
                push(&stack, result_str);
            }
        }
        free(c);
    }
    result = strtod(stack->data, NULL);

    destroy(&stack);
    return result;
}

char* is_X(char* ch, int curr) {
    if (strcmp(ch, "x") == 0 || strcmp(ch, "X") == 0) {
        char str_curr[20];
        sprintf(str_curr, "%lf", (double)curr);
        free(ch);
        ch = strdup(str_curr);
    }
    return ch;
}

int is_digit(char* ch) {
    int flag = 0;

    char* endptr;
    strtod(ch, &endptr);
    if (*endptr == '\0') {
        flag = 1;
    }
    return flag;
}