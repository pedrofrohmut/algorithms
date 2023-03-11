#include <stdio.h>
#include <stdlib.h>

// STACK
// methods
//     push
//     pop
//     peek
//     print_nodes
//     free_nodes
//     create_stack
#include "../headers/Stack.h"

int main()
{
    Stack * stack = create_stack();

    // Populate
    printf("\n> Populating with (Once Upon a Time)\n");
    push(stack, "Once");
    push(stack, "Upon");
    push(stack, "a");
    push(stack, "Time");

    printf("\n> Print stack after populate [Size = %zu]\n", size(stack));
    print_nodes(stack);

    // Push extra values
    printf("\n> Populating with (VIRUS_1 VIRUS_2 VIRUS_3)\n");
    push(stack, "VIRUS_1");
    push(stack, "VIRUS_2");
    push(stack, "VIRUS_3");

    printf("\n> Print stack after pushing viruses [Size = %zu]\n", size(stack));
    print_nodes(stack);

    // Pop 3 nodes
    printf("\n> Pop 3 Nodes\n");
    Stack_Node * node1 = pop(stack);
    Stack_Node * node2 = pop(stack);
    Stack_Node * node3 = pop(stack);
    printf("%s popped\n", node1 != NULL ? node1->value : "NULL");
    printf("%s popped\n", node2 != NULL ? node2->value : "NULL");
    printf("%s popped\n", node3 != NULL ? node3->value : "NULL");
    free(node1);
    free(node2);
    free(node3);

    printf("\n> Print stack after popping 3 nodes\n");
    print_nodes(stack);

    // Peek top value
    printf("\n> Peek Stack\n");
    char * peek_value = peek(stack);
    printf("Value: %s\n", peek_value);
    free(peek_value);

    printf("\n> Free Nodes\n");
    free_nodes(stack);

    free(stack);

    return 0;
}

