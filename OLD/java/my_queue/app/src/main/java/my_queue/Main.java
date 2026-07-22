package my_queue;

public class Main {

    public static void main(String args[]) {
        var q_default = new Queue<Integer>();
        System.out.println("Default capacity: " + q_default.capacity());

        var q = new Queue<Integer>(10);
        System.out.println("Custom capacity: " + q.capacity());
        System.out.println("Size: " + q.size());

        System.out.println("\nPopulating queue");
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.enqueue(4);
        q.enqueue(5);
        q.printQueue();

        System.out.println("\nPrinting Reverse Order");
        q.printQueueReverse();

        var x1 = q.dequeue();
        System.out.println("\nDequeue 1: " + x1);
        System.out.println("\nAfter dequeue");
        q.printQueue();

        System.out.println("\nHead: " + q.head());
        System.out.println("Tail: " + q.tail());

        System.out.println("\nAt 2: " + q.findByIndex(2));
        System.out.println("Where is 3: " + q.findByValue(3));

        System.out.println("\nString queue");
        var sq = new Queue<String>();
        sq.enqueue("Foo");
        sq.enqueue("Bar");
        sq.enqueue("Baz");
        sq.enqueue("Buz");
        sq.printQueue();

        sq.deleteByIndex(2);
        System.out.println("\nDeleted at 2");
        sq.printQueue();

        sq.deleteNodeByValue("Bar");
        System.out.println("\nDeleted at Bar");
        sq.printQueue();
    }
}
