#ifndef STACK_HEADER
#define STACK_HEADER

#include <stddef.h>

// STACK
// methods
//     stack_create_stack
//     stack_push
//     stack_pop
//     stack_peek
//     stack_size
//     stack_print_nodes
//     stack_free_nodes

typedef struct Stack_Node {
    char * value;
    struct Stack_Node * next;
} Stack_Node;

typedef struct Stack {
    size_t size;
    Stack_Node * top;
} Stack;

Stack * stack_create_stack();

void stack_push(Stack * stack, const char * value);
Stack_Node * stack_pop(Stack * stack);
char * stack_peek(Stack * stack);
size_t stack_size(Stack * stack);
void stack_print_nodes(Stack * stack);
void stack_free_nodes(Stack * stack);

#endif // STACK_HEADER
