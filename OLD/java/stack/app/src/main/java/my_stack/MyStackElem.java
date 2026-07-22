package my_stack;

public class MyStackElem<T> {

    public T data;
    public MyStackElem<T> next;

    public MyStackElem() {}

    public MyStackElem(T data) {
        this.data = data;
    }
}
