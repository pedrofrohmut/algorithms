package my_stack;

public class MyStack<T> implements IMyStack<T>
{
    private class Elem<T>
    {
        public T data;
        public Elem<T> next;

        public Elem() {}

        public Elem(T data) { this.data = data; }
    }

    private Elem<T> top;

    public MyStack() {
        this.top = null;
    }

	@Override
	public boolean isEmpty() {
        return top == null;
	}

	@Override
	public T peek() {
        return top.data;
	}

	@Override
	public T pop() {
        var temp = top;
        top = top.next;
        return temp.data;
	}

	@Override
	public void push(T data) {
        var e = new Elem<T>(data);
        e.next = top;
        top = e;
	}

	@Override
	public int search(T searched) {
        int i = 0;
        var x = top;
        while (x != null) {
            if (x.data.equals(searched)) {
                return i;
            }
            x = x.next;
            i++;
        }
        return -1;
	}

	@Override
	public void printStack() {
        System.out.println("Printing stack:");

        if (isEmpty()) {
            System.out.println("The stack is empty");
            return;
        }

        var x = top;
        int i = 0;
        while (x != null) {
            System.out.printf("[%d]: %s", i, x.data);
            if (i == 0) System.out.printf(" (TOP)");
            System.out.printf("\n");
            x = x.next;
            i++;
        }
	}
}
