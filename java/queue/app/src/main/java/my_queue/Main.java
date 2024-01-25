package my_queue;

public class Main {
    public static void main(String args[]) {
        var queue = new Queue<Integer>();
        queue.add(1);
        queue.add(2);
        queue.add(3);
        queue.add(4);
        queue.add(5);
        queue.add(6);
        queue.add(7);
        System.out.println("Print queue from head");
        queue.printQueue();
        System.out.println("Print queue (reverse) from tail");
        queue.printQueueReverse();
    }
}
