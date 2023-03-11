#ifndef QUEUE_HEADER
#define QUEUE_HEADER

#include <stddef.h>

// QUEUES (FIFO - First In First Out)
// methods
//     enqueue
//     dequeue
//     create_queue
//     print_nodes

typedef struct Queue_Node {
    const char * value;
    struct Queue_Node * prev;
    struct Queue_Node * next;
} Queue_Node;

typedef struct Queue {
    Queue_Node * first;
    Queue_Node * last;
    size_t size;
} Queue;

Queue * create_queue();
void enqueue(Queue * queue, const char * value);
char * dequeue(Queue * queue);
void print_nodes(const Queue * queue);
void free_queue(Queue * queue);

#endif
