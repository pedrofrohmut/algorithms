#include <stdio.h>
#include <stdlib.h>

// QUEUES (FIFO - First In First Out)
// methods
//     enqueue
//     dequeue
//     create_queue
//     print_nodes
#include "../headers/Queue.h"

int main()
{
    Queue * queue = create_queue();

    // Populate
    enqueue(queue, "Once");
    enqueue(queue, "Upon");
    enqueue(queue, "a");
    enqueue(queue, "Time");

    printf("\n> Print after populate (Once Upon a Time) [Size = %zu]\n", queue->size);
    print_nodes(queue);

    // Dequeue all values
    printf("\n> Dequeue 5 times\n");
    Node * node1 = dequeue(queue);
    Node * node2 = dequeue(queue);
    Node * node3 = dequeue(queue);
    Node * node4 = dequeue(queue);
    Node * node5 = dequeue(queue); // Extra to test on empty queue
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);

    printf("\n> Print after dequeue 5 times\n");
    print_nodes(queue);

    // Populate 2
    enqueue(queue, "foo");
    enqueue(queue, "bar");
    enqueue(queue, "baz");

    printf("\n> Print after populate (foo bar baz) [Size = %zu]\n", queue->size);
    print_nodes(queue);

    printf("\n> Free Queue\n");
    free_queue(queue);

    free(queue);

    return 0;
}
