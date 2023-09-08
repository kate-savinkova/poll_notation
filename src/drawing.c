#include "drawing.h"

void print_graph(Stack func_in_pol_not) {
    Stack tmp_stack = NULL, tmp2 = NULL;
    while (func_in_pol_not != NULL) {
        char* c = pop(&func_in_pol_not);
        push(&tmp_stack, c);
        free(c);
    }
    // tmp_stack = clone_stack(&func_in_pol_not);
    tmp2 = clone_stack(&tmp_stack);
    // free(func_in_pol_not);
    double space = 2. / (HEIGHT - 1);
    for (double y = -1; y <= 1; y += space) {
        for (double x = 0; x <= 4 * M_PI; x += (4 * M_PI) / (80 - 1)) {
            tmp_stack = clone_stack(&tmp2);
            double func = calc_result(&tmp_stack, x);
            // double func = anezy(x);
            if (func >= y && func <= (space + y))
                printf("*");
            else
                printf(".");
        }
        printf("\n");
    }
    destroy(&tmp2);
    destroy(&tmp_stack);
}
