using System;

namespace DS_LinkedList;

public class LinkedList<T>
{
    private class Node<U>
    {
        public U value;
        public Node<U>? next;

        public Node(U value)
        {
            this.value = value;
            this.next = null;
        }
    }

    private Node<T>? first;
    private uint size;

    public LinkedList()
    {
        this.first = null;
        this.size = 0;
    }

    public T? GetFirst()
    {
        if (this.first == null) {
            return default(T);
        } else {
            return this.first.value;
        }
    }

    public uint GetSize()
    {
        return this.size;
    }

    public void Add(T value)
    {
        var newNode = new Node<T>(value);

        this.size += 1;

        if (this.first == null) {
            this.first = newNode;
            return;
        }

        var curr = this.first;
        while (curr.next != null) {
            curr = curr.next;
        }
        curr.next = newNode;

    }

    public void Remove()
    {
        if (this.first == null) return;
        this.size -= 1;
        this.first = this.first.next;
    }

    private void PrintNode(Node<T> node) => Console.WriteLine(node.value);

    public void PrintList()
    {
        if (this.first == null) {
            Console.WriteLine("List is empty");
            return;
        }
        var curr = this.first;
        while (curr != null) {
            PrintNode(curr);
            curr = curr.next;
        }
    }
}
