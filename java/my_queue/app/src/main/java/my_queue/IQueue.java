package my_queue;

public interface IQueue<T> {

    void enqueue(T item);

    T dequeue();

    void printQueue();

    void printQueueReverse();

    long size();

    long capacity();

    T head();

    T tail();

    T findByIndex(long index);

    long findByValue(T value);

    void deleteByIndex(long index);

    void deleteNodeByValue(T value);
}
