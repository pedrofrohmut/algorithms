#include "../headers/Queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Queue * create_queue()
{
    Queue * new_queue = malloc(sizeof(Queue));
    new_queue->first = NULL;
    new_queue->last = NULL;
    new_queue->size = 0;
    return new_queue;
}

void enqueue(Queue * queue, const char * value)
{
    // Prepare new node
    Node * new_node = malloc(sizeof(Node));
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

Node * dequeue(Queue * queue)
{
    if (queue->size < 1) return NULL;

    Node * old_last;
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
    return old_last;
}

void print_nodes(const Queue * queue)
{
    Node * iterator = queue->first;
    size_t counter = 0;

    // Iterate full queue
    while (iterator != NULL) {
        printf("[%zu] %s\n", counter, iterator->value);
        iterator = iterator->next;
        counter++;
    }
}

void free_queue(Queue * queue)
{
    Node * iterator = queue->first;

    // Iterate full queue
    while (iterator != NULL) {
        Node * temp = iterator;
        iterator = iterator->next;
        free(temp);
    }
}