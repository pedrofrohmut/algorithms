package my_queue;

public class Queue<E> implements IQueue<E> {

    private long size;
    private long capacity;

    private class Elem<T> {
        T data;
        Elem<T> prev;
        Elem<T> next;
    }

    private Elem<E> head;
    private Elem<E> tail;

    public Queue() {
        this.size = 0;
        this.capacity = Long.MAX_VALUE;
        this.head = null;
        this.tail = null;
    }

    public Queue(long capacity) {
        this(); // Load defaults
        this.capacity = capacity;
    }

    @Override
    public long size() { return size; }

    @Override
    public boolean add(E data) {
        if (size >= capacity) throw new IllegalStateException("Queue is full");

        var elem = new Elem<E>();
        elem.data = data;
        elem.prev = null;
        elem.next = tail;

        if (head == null) head = elem;
        if (tail != null) tail.prev = elem;
        tail = elem;
        size++;

        return true;
    }

    @Override
    public E element() {
        if (head != null) return head.data;
        return null;
    }

    @Override
    public boolean offer(E data) {
        try {
            add(data);
            return true;
        } catch (IllegalStateException x) {
            return false;
        }
    }

    @Override
    public E peek() {
        return element();
    }

    @Override
    public E poll() {
        if (size == 0) return null;
        var res = head.data;
        head = head.prev;
        head.next = null;
        size--;
        return res;
    }

    @Override
    public E remove() {
        return poll();
    }

    @Override
    public void printQueue() {
        var x = head;
        var i = 0;
        while (x != null) {
            System.out.println("[" + i + "]: " + x.data);
            x = x.prev;
            i++;
        }
    }

    @Override
    public void printQueueReverse() {
        var x = tail;
        var i = 0;
        while (x != null) {
            System.out.println("[" + i + "]: " + x.data);
            x = x.next;
            i++;
        }
    }

}
