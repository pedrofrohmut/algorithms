package my_queue;

/*
    Queue: FIFO (first in first out) data struct. Like a line of people. A collection
    design for holding elements prior to processing Linear data structure.
*/
public interface IQueue<E> {

    // Returns the size of the queue
    long size();

    // Inserts the specified element into this queue if it is possible to do so
    // immediately without violating capacity restrictions, returning true upon
    // success and throwing an IllegalStateException if no space is currently
    // available.
    boolean add(E e);

    // Retrieves, but does not remove, the head of this queue.
    E element();

    // Inserts the specified element into this queue if it is possible to do so
    // immediately without violating capacity restrictions.
    boolean offer(E e);

    // Retrieves, but does not remove, the head of this queue, or returns null if
    // this queue is empty.
    E peek();

    // Retrieves and removes the head of this queue, or returns null if this queue
    // is empty.
    E poll();

    // Retrieves and removes the head of this queue.
    E remove();

    // Prints the list to stdout head to tail
    void printQueue();

    // Prints the list to stdout but starting from tail to head
    void printQueueReverse();
}
