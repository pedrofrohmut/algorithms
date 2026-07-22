package my_stack;

public class Main {

    public static void main(String args[]) {
        var stack = new MyStack<String>();

        boolean isEmpty = stack.isEmpty();
        System.out.println("Is empty: " + isEmpty);

        stack.printStack();

        stack.push("Foo");
        stack.push("Bar");
        stack.push("Baz");

        stack.printStack();

        var peeked = stack.peek();
        System.out.println("Peeked: " + peeked);

        var poped = stack.pop();
        System.out.println("Poped: " + poped);
        stack.printStack();

        stack.push("Bob");
        stack.push("Sarah");
        stack.push("John");
        stack.push("Mike");
        stack.printStack();
        System.out.println("Sarah at: " + stack.search("Sarah"));
        System.out.println("John at: " + stack.search("John"));
        System.out.println("Foo at: " + stack.search("Foo"));
    }
}
