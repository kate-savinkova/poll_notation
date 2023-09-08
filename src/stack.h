#ifndef STACK_H
#define STACK_H

typedef struct Stack_Node {
    char* data;
    struct Stack_Node* next;
} Stack_Node;

typedef Stack_Node* Stack;

Stack_Node* init_stack_node(char* data);
void push(Stack* root, char* data);
char* pop(Stack* root);
void destroy(Stack* root);
Stack clone_stack(const Stack* root);
#endif
