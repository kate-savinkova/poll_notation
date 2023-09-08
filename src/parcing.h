#ifndef PARCING
#define PARCING

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** parse_string(const char* str);
int is_valid_token(char* token);
int check_balance_and_validity(char** tokens);
char** input(char* str);

#endif