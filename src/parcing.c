#include "parcing.h"

char **parse_string(const char *str) {
    char **parsed_string = NULL;
    size_t size = 0;
    size_t buffer_size = 0;
    char *buffer = NULL;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '(' ||
            str[i] == ')') {
            if (buffer_size > 0) {
                char **temp = (char **)realloc(parsed_string, (size + 2) * sizeof(char *));
                if (temp != NULL) {
                    parsed_string = temp;
                    parsed_string[size] = strdup(buffer);
                    parsed_string[size + 1] = NULL;
                    size++;
                    buffer_size = 0;
                    free(buffer);
                    buffer = NULL;
                } else {
                    free(parsed_string);
                    parsed_string = NULL;
                }
            }
            parsed_string = (char **)realloc(parsed_string, (size + 2) * sizeof(char *));
            parsed_string[size] = (char *)malloc(2 * sizeof(char));
            parsed_string[size][0] = str[i];
            parsed_string[size][1] = '\0';
            parsed_string[size + 1] = NULL;
            size++;
        } else {
            char *temp = (char *)realloc(buffer, (buffer_size + 2) * sizeof(char));
            if (temp != NULL) {
                buffer = temp;
                buffer[buffer_size] = str[i];
                buffer[buffer_size + 1] = '\0';
                buffer_size++;
            } else {
                free(buffer);
                buffer = NULL;
            }
        }
    }

    if (buffer_size > 0) {
        parsed_string = (char **)realloc(parsed_string, (size + 2) * sizeof(char *));
        parsed_string[size] = strdup(buffer);
        parsed_string[size + 1] = NULL;
        free(buffer);
    }

    return parsed_string;
}

int is_valid_token(char *token) {
    int status = 0;
    // Перечисление всех допустимых токенов
    const char *valid_tokens[] = {"sin", "cos", "tan", "ctg", "sqrt", "ln", "x",
                                  "(",   ")",   "/",   "*",   "-",    "+"};
    size_t num_valid_tokens = sizeof(valid_tokens) / sizeof(valid_tokens[0]);

    // Проверка на числовой токен
    char *endptr;
    strtod(token, &endptr);
    if (*endptr == '\0') {
        status = 1;
    }

    if (strlen(token) == 0) {
        status = 0;  // Пустой токен
    }

    // Проверка на вхождение токена в список допустимых
    for (size_t i = 0; i < num_valid_tokens; i++) {
        if (strcmp(token, valid_tokens[i]) == 0) {
            status = 1;
        }
    }

    return status;  // Невалидный токен
}

int check_balance_and_validity(char **tokens) {
    int balance = 0;
    int flag = 0;

    for (int i = 0; tokens[i] != NULL; i++) {
        if (is_valid_token(tokens[i]) == 0) {
            flag = 1;
            break;
        }
        if (*tokens[i] == '(')
            balance++;
        else if (*tokens[i] == ')')
            balance--;
    }

    if (balance != 0) {
        flag = 1;
    }

    return flag;
}

char **input(char *str) {
    str = (char *)malloc(0 * sizeof(char));
    char **res = NULL;
    int flag = 0, count = 0, i = 0;
    char curr = getchar();
    while (curr != '\n') {
        str = (char *)realloc(str, count * sizeof(char));
        str[i] = curr;
        i++;
        count++;
        curr = getchar();
    }
    res = parse_string(str);  // парсим строчку в массив лексем
    flag = check_balance_and_validity(res);
    if (flag == 1) {
        printf("Invalid input.\n");
        res = NULL;
    }
    free(str);
    return res;
}