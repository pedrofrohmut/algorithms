#include <stdio.h>
#include <stdlib.h>

// STACK
// methods
//     stack_push
//     stack_pop
//     stack_peek
//     stack_print_nodes
//     stack_free_nodes
//     stack_create_stack
#include "../headers/Stack.h"

int main()
{
    Stack * stack = stack_create_stack();

    // Populate
    printf("\n> Populating with (Once Upon a Time)\n");
    stack_push(stack, "Once");
    stack_push(stack, "Upon");
    stack_push(stack, "a");
    stack_push(stack, "Time");

    printf("\n> Print stack after populate [Size = %zu]\n", stack_size(stack));
    stack_print_nodes(stack);

    // Push extra values
    printf("\n> Populating with (VIRUS_1 VIRUS_2 VIRUS_3)\n");
    stack_push(stack, "VIRUS_1");
    stack_push(stack, "VIRUS_2");
    stack_push(stack, "VIRUS_3");

    printf("\n> Print stack after pushing viruses [Size = %zu]\n", stack_size(stack));
    stack_print_nodes(stack);

    // Pop 3 nodes
    printf("\n> Pop 3 Nodes\n");
    Stack_Node * node1 = stack_pop(stack);
    Stack_Node * node2 = stack_pop(stack);
    Stack_Node * node3 = stack_pop(stack);
    printf("%s popped\n", node1 != NULL ? node1->value : "NULL");
    printf("%s popped\n", node2 != NULL ? node2->value : "NULL");
    printf("%s popped\n", node3 != NULL ? node3->value : "NULL");
    free(node1);
    free(node2);
    free(node3);

    printf("\n> Print stack after popping 3 nodes\n");
    stack_print_nodes(stack);

    // Peek top value
    printf("\n> Peek Stack\n");
    char * peek_value = stack_peek(stack);
    printf("Value: %s\n", peek_value);
    free(peek_value);

    printf("\n> Free Nodes\n");
    stack_free_nodes(stack);

    free(stack);

    return 0;
}

