#include "graph.h"

int main() {
    char* str = "";
    char** new_str = input(str);
    if (new_str != NULL) {
        Stack result = poll_notation(new_str);  // преобразуем в обратную польскую нотацию
        print_graph(result);                    // выводим граф
        // начинается очистка памяти
        destroy(&result);
        for (int i = 0; new_str[i] != NULL; i++) {
            free(new_str[i]);
        }
    }
    free(new_str);
    return 0;
}
