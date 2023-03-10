#ifndef QUEUE_HEADER
#define QUEUE_HEADER

#include <stddef.h>

// QUEUES (FIFO - First In First Out)
// methods
//     enqueue
//     dequeue
//     create_queue
//     print_nodes

typedef struct Node {
    const char * value;
    struct Node * prev;
    struct Node * next;
} Node;

typedef struct Queue {
    Node * first;
    Node * last;
    size_t size;
} Queue;

Queue * create_queue();
void enqueue(Queue * queue, const char * value);
Node * dequeue(Queue * queue);
void print_nodes(const Queue * queue);
void free_queue(Queue * queue);

#endif
