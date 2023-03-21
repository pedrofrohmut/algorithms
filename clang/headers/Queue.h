#ifndef QUEUE_HEADER
#define QUEUE_HEADER

#include <stddef.h>

// QUEUES (FIFO - First In First Out)
// methods
//     queue_enqueue
//     queue_dequeue
//     queue_create_queue
//     queue_print_nodes

typedef struct Queue_Node {
    char * value;
    struct Queue_Node * prev;
    struct Queue_Node * next;
} Queue_Node;

typedef struct Queue {
    Queue_Node * first;
    Queue_Node * last;
    size_t size;
} Queue;

Queue * queue_create_queue();

void queue_enqueue(Queue * queue, const char * value);
char * queue_dequeue(Queue * queue);
void queue_print_nodes(const Queue * queue);
void queue_free_queue(Queue * queue);

#endif
