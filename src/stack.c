#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Stack_Node* init_stack_node(char* data) {
    Stack_Node* root = (Stack_Node*)malloc(sizeof(Stack_Node));
    if (root != NULL) {
        root->data = strdup(data);
        root->next = NULL;
    }
    return root;
}

void push(Stack* root, char* data) {
    Stack_Node* new_node = init_stack_node(data);
    new_node->next = *root;
    *root = new_node;
}

char* pop(Stack* root) {
    char* data = NULL;
    if (*root != NULL) {
        Stack_Node* temp = *root;
        *root = (*root)->next;
        data = temp->data;
        free(temp);
    }
    return data;
}

void destroy(Stack* root) {
    while (*root != NULL) {
        free(pop(root));
    }
}

Stack clone_stack(const Stack* root) {
    Stack_Node* temp = *root;
    Stack clone = NULL;

    Stack_Node* clone_top = NULL;  // Вершина клонированного стека

    while (temp != NULL) {
        // Клонируем данные текущего узла
        Stack_Node* new_node = init_stack_node(temp->data);
        if (new_node == NULL) {
            // Обработка ошибки
            destroy(&clone);  // Освобождаем память, выделенную для клонированного стека
            return NULL;
        }

        // Добавляем узел к клонированному стеку
        if (clone_top == NULL) {
            clone_top = new_node;
            clone = clone_top;
        } else {
            clone_top->next = new_node;
            clone_top = new_node;
        }

        temp = temp->next;
    }

    return clone;
}
