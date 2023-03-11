#include "../headers/Stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Stack * create_stack()
{
    Stack * new_stack = malloc(sizeof(Stack));
    new_stack->size = 0;
    new_stack->top = NULL;
    return new_stack;
}

void push(Stack * stack, const char * value)
{
    Stack_Node * new_node = malloc(sizeof(Stack_Node));
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
}

Stack_Node * pop(Stack * stack)
{
    if (stack->top == NULL) return NULL;
    Stack_Node * temp = stack->top;
    stack->top = stack->top->next;
    return temp;
}

char * peek(Stack * stack)
{
    char * value = malloc(sizeof(stack->top->value) + 1);
    strcpy(value, stack->top->value);
    return value;
}

size_t size(Stack * stack)
{
    return stack->size;
}

void print_nodes(Stack * stack)
{
    Stack_Node * iterator = stack->top;
    size_t counter = 0;
    while (iterator != NULL) {
        printf("[%zu] %s\n", counter, iterator->value);
        iterator = iterator->next;
        counter++;
    }
}

void free_nodes(Stack * stack)
{
    Stack_Node * iterator = stack->top;
    while (iterator != NULL) {
        Stack_Node * temp = iterator;
        iterator = iterator->next;
        printf("Debug: freed node with value %s\n", temp->value);
        free(temp);
    }
}

