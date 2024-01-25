package my_stack;

public interface IMyStack<T> {
    // Tests if this stack is empty.
    boolean isEmpty();

    // Looks at the object at the top of this stack without removing it from the stack.
    T peek();

    // Removes the object at the top of this stack and returns that object as the value of this function.
    T pop();

    // Pushes an item onto the top of this stack.
    void push(T data);

    // Returns the 1-based position where an object is on this stack.
    int search(T searched);

    void printStack();
}
