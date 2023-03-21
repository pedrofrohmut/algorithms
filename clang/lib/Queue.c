#include "../headers/Queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Queue * queue_create_queue()
{
    Queue * new_queue = malloc(sizeof(Queue));
    new_queue->first = NULL;
    new_queue->last = NULL;
    new_queue->size = 0;
    return new_queue;
}

void queue_enqueue(Queue * queue, const char * value)
{
    // Prepare new node
    Queue_Node * new_node = malloc(sizeof(Queue_Node));
    new_node->prev = NULL;
    new_node->value = value;

    // Arrange pointers
    new_node->next = queue->first;
    if (queue->first != NULL) {
        queue->first->prev = new_node;
    } else {
        queue->last = new_node;
    }
    queue->first = new_node;

    queue->size++;
}

char * queue_dequeue(Queue * queue)
{
    if (queue->size < 1) return NULL;

    Queue_Node * old_last;
    if (queue->size == 1) {
        old_last = queue->first;
        queue->last = NULL;
        queue->first = NULL;
    } else {
        old_last = queue->last;
        queue->last = old_last->prev;
        queue->last->next = NULL;
    }
    queue->size--;

    char * value = malloc(strlen(old_last->value) + 1);
    strcpy(value, old_last->value);

    free(old_last);

    return value;
}

void queue_print_nodes(const Queue * queue)
{
    Queue_Node * iterator = queue->first;
    size_t counter = 0;

    // Iterate full queue
    while (iterator != NULL) {
        printf("[%zu] %s\n", counter, iterator->value);
        iterator = iterator->next;
        counter++;
    }
}

void queue_free_queue(Queue * queue)
{
    Queue_Node * iterator = queue->first;

    // Iterate full queue
    while (iterator != NULL) {
        Queue_Node * temp = iterator;
        iterator = iterator->next;
        free(temp);
    }
}
