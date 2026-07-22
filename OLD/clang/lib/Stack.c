#include "../headers/Stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Stack * stack_create_stack()
{
    Stack * new_stack = malloc(sizeof(Stack));
    new_stack->size = 0;
    new_stack->top = NULL;
    return new_stack;
}

Stack_Node * _prepare_new_node(const char * value)
{
    Stack_Node * new_node = malloc(sizeof(Stack_Node));
    new_node->value = malloc(strlen(value) + 1);
    strcpy(new_node->value, value);
    new_node->next = NULL;
    return new_node;
}

void stack_push(Stack * stack, const char * value)
{
    Stack_Node * new_node = _prepare_new_node(value);
    new_node->next = stack->top;
    stack->top = new_node;
}

Stack_Node * stack_pop(Stack * stack)
{
    if (stack->top == NULL) return NULL;
    Stack_Node * temp = stack->top;
    stack->top = stack->top->next;
    return temp;
}

char * stack_peek(Stack * stack)
{
    char * value = malloc(sizeof(stack->top->value) + 1);
    strcpy(value, stack->top->value);
    return value;
}

size_t stack_size(Stack * stack)
{
    return stack->size;
}

void stack_print_nodes(Stack * stack)
{
    Stack_Node * iterator = stack->top;
    size_t counter = 0;
    while (iterator != NULL) {
        printf("[%zu] %s\n", counter, iterator->value);
        iterator = iterator->next;
        counter++;
    }
}

void _free_node(Stack_Node * node)
{
    free(node->value);
    free(node);
}

void stack_free_nodes(Stack * stack)
{
    Stack_Node * iterator = stack->top;
    while (iterator != NULL) {
        Stack_Node * tmp = iterator;
        iterator = iterator->next;
        printf("Debug: freed node with value %s\n", tmp->value);
        _free_node(tmp);
    }
}

