#ifndef POLL
#define POLL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parcing.h"
#include "stack.h"

int priority(char* ch);
Stack_Node* poll_notation(char** new_str);

#endif