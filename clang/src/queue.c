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
    char * first_value = dequeue(queue);
    char * node2_value = dequeue(queue);
    char * node3_value = dequeue(queue);
    char * last_value  = dequeue(queue);
    char * extra_value = dequeue(queue); // Extra to test on empty queue

    printf("\n> Print dequeued values\n");
    printf("First node value:  %s\n", first_value);
    printf("Second node value: %s\n", node2_value);
    printf("Third node value:  %s\n", node3_value);
    printf("Last node value:   %s\n", last_value);
    printf("Extra node value:  %s\n", extra_value);

    printf("\n> Free the dequeued values\n");
    free(first_value);
    free(node2_value);
    free(node3_value);
    free(last_value);
    free(extra_value);

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
