#ifndef STACK_HEADER
#define STACK_HEADER

#include <stddef.h>

// STACK
// methods
//     create_stack
//     push
//     pop
//     peek
//     size
//     print_nodes
//     free_nodes

typedef struct Stack_Node {
    const char * value;
    struct Stack_Node * next;
} Stack_Node;

typedef struct Stack {
    size_t size;
    Stack_Node * top;
} Stack;

Stack * create_stack();
void push(Stack * stack, const char * value);
Stack_Node * pop(Stack * stack);
char * peek(Stack * stack);
size_t size(Stack * stack);
void print_nodes(Stack * stack);
void free_nodes(Stack * stack);

#endif // STACK_HEADER
