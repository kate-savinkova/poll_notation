#include "poll_notation.h"

Stack poll_notation(char** new_str) {
    Stack tmp = NULL, result = NULL;
    int i = 0, was_there_open = 0, flag = 0;
    while (new_str[i] != NULL && flag == 0) {
        int prior = priority(new_str[i]);
        if (prior == 6) {  // числа
            push(&result, new_str[i]);
        } else if (prior == 5) {  // закр. скобка
            if (was_there_open) {
                while (strcmp(tmp->data, "(") != 0) {
                    char* pop_ch = pop(&tmp);
                    push(&result, pop_ch);
                    free(pop_ch);
                }
                char* pop_ch = pop(&tmp);
                free(pop_ch);
            } else {
                flag = 1;  // если нет открывающей скобки
            }
        } else if (prior == 4) {
            push(&tmp, new_str[i]);
            was_there_open = 1;
        } else if (tmp == NULL) {
            push(&tmp, new_str[i]);
        } else if (prior > priority(tmp->data)) {
            push(&tmp, new_str[i]);
        } else {
            while (tmp != NULL && prior <= priority(tmp->data) && strcmp(tmp->data, "(") != 0) {
                char* pop_ch = pop(&tmp);
                push(&result, pop_ch);
                free(pop_ch);
            }
            push(&tmp, new_str[i]);
        }
        i++;
    }
    while (tmp != NULL) {
        char* pop_ch = pop(&tmp);
        push(&result, pop_ch);
        free(pop_ch);
    }
    destroy(&tmp);
    return flag ? NULL : result;
}

int priority(char* ch) {
    int result;
    if (strcmp(ch, "+") == 0 || strcmp(ch, "-") == 0)
        result = 0;
    else if (strcmp(ch, "*") == 0 || strcmp(ch, "/") == 0)
        result = 1;
    else if (strcmp(ch, "sin") == 0 || strcmp(ch, "cos") == 0 || strcmp(ch, "tan") == 0 ||
             strcmp(ch, "ctg") == 0 || strcmp(ch, "sqrt") == 0 || strcmp(ch, "ln") == 0)
        result = 2;
    else if (strcmp(ch, "^") == 0)
        result = 3;
    else if (strcmp(ch, "(") == 0)
        result = 4;
    else if (strcmp(ch, ")") == 0)
        result = 5;
    else
        result = 6;  // int
    return result;
}