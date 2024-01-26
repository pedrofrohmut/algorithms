package my_queue;

public class Queue<T> implements IQueue<T> {

    private class Node<T> {
        T data;
        Node<T> prev;
        Node<T> next;
    }

    private Node<T> head;
    private Node<T> tail;
    private long size;
    private long capacity;

    public Queue() {
        this.capacity = Long.MAX_VALUE;
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    public Queue(long capacity) {
        this(); // load defaults
        this.capacity = capacity;
    }

	@Override
	public void enqueue(T data) {
        if (size >= capacity) throw new IllegalStateException("Queue is full");

        var node = new Node<T>();
        node.data = data;
        node.prev = null;

        if (head == null) head = node;
        if (tail != null) tail.prev = node;
        node.next = tail;
        tail = node;

        size++;
	}

	@Override
	public T dequeue() {
        if (head == null) return null;

        var res = head.data;

        if (head.prev == null) {
            head = null;
            tail = null;
        } else {
            head = head.prev;
            head.next = null;
        }

        return res;
	}

	@Override
	public void printQueue() {
        if (size == 0) return;
        var x = head;
        long i = 0;
        while (x != null) {
            System.out.print("[" + i + "]: " + x.data);
            if (i == 0) System.out.print(" (HEAD)");
            System.out.print("\n");
            x = x.prev;
            i++;
        }
	}

	@Override
	public void printQueueReverse() {
        if (size == 0) return;
        var x = tail;
        long i = size - 1;
        while (x != null) {
            System.out.print("[" + i + "]: " + x.data);
            if (i == size - 1) System.out.print(" (TAIL)");
            System.out.print("\n");
            x = x.next;
            i--;
        }
	}

	@Override
	public long size() { return size; }

	@Override
	public long capacity() { return capacity; }

	@Override
	public T head() { return head.data; }

	@Override
	public T tail() { return tail.data; }

	@Override
	public T findByIndex(long index) {
        if (size == 0) return null;
        if (index > size) return null;
        var x = head;
        long i = 0;
        while (x != null) {
            if (i == index) return x.data;
            x = x.prev;
            i++;
        }
        return null;
    }

	@Override
	public long findByValue(T value) {
        if (size == 0) return -1;
        var x = head;
        long i = 0;
        while (x != null) {
            if (x.data.equals(value)) return i;
            x = x.prev;
            i++;
        }
        return -1;
	}

	@Override
	public void deleteByIndex(long index) {
        if (size == 0) return;
        if (index > size) return;
        var x = head;
        long i = 0;
        while (x != null) {
            if (i == index) {
                var temp = x.prev;
                temp.next = x.next;
                x.next.prev = temp;
                return;
            }
            x = x.prev;
            i++;
        }
	}

	@Override
	public void deleteNodeByValue(T value) {
        if (size == 0) return;
        var x = head;
        long i = 0;
        while (x != null) {
            if (x.data.equals(value)) {
                var temp = x.prev;
                temp.next = x.next;
                x.next.prev = temp;
                return;
            }
            x = x.prev;
            i++;
        }
	}
}
