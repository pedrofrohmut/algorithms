package my_queue;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class QueueTest {

    @Test
    void emptyQueue_SizeIsZero() {
        var queue = new Queue<String>();
        assertEquals(queue.size(), 0);
    }

    @Test
    void addElem_SizeIsOne() {
        var queue = new Queue<String>();
        queue.add("Foo");
        assertEquals(queue.size(), 1);
    }

    @Test
    void canAddElem_BelowCapacity() {
        var queue = new Queue<Integer>(5);
        assertTrue(queue.add(1));
        assertTrue(queue.add(2));
        assertTrue(queue.add(3));
        assertTrue(queue.add(4));
        assertEquals(queue.size(), 4);
    }

    @Test
    void cannotAddElem_AboveCapacity() {
        var queue = new Queue<Integer>(3);
        assertTrue(queue.add(1));
        assertTrue(queue.add(2));
        assertTrue(queue.add(3));
        assertThrows(IllegalStateException.class, () -> queue.add(4));
        assertEquals(queue.size(), 3);
    }

    @Test
    void getHead_AndDoesNotChangeSize() {
        var queue = new Queue<Integer>();
        queue.add(1);
        queue.add(2);
        queue.add(3);
        queue.add(4);
        assertEquals(queue.size(), 4);

        var x = queue.element();
        System.out.println("X: " + x);
        assertEquals(x, 1);
        assertEquals(queue.size(), 4);
    }

    @Test
    void canOffer_BelowCapacity() {
        var queue = new Queue<Integer>(5);
        assertTrue(queue.offer(1));
        assertTrue(queue.offer(2));
        assertTrue(queue.offer(3));
        assertTrue(queue.offer(4));
        assertEquals(queue.size(), 4);
    }

    @Test
    void cannotOffer_AboveCapacity() {
        var queue = new Queue<Integer>(3);
        assertTrue(queue.offer(1));
        assertTrue(queue.offer(2));
        assertTrue(queue.offer(3));
        assertFalse(queue.offer(4));
        assertEquals(queue.size(), 3);
    }

    @Test
    void peekEmpty_ReturnsNull() {
        var queue = new Queue<Integer>();
        assertNull(queue.peek());
    }

    @Test
    void peekNonEmpty_ReturnsHead_PreserveSize() {
        var queue = new Queue<Integer>();
        queue.add(1);
        queue.add(2);
        queue.add(3);
        queue.add(4);
        assertEquals(queue.size(), 4);

        var head = queue.peek();
        assertEquals(head, 1);
        assertEquals(queue.size(), 4);
    }

    @Test
    void pollEmpty_ReturnsNull() {
        var queue = new Queue<Integer>();
        assertEquals(queue.size(), 0);
        assertNull(queue.poll());
    }

    @Test
    void pollNonEmpty_RetrieveAndRemovesHead() {
        var queue = new Queue<Integer>();
        queue.add(1);
        queue.add(2);
        queue.add(3);
        queue.add(4);
        assertEquals(queue.size(), 4);

        var x = queue.poll();
        assertEquals(x, 1);
        assertNotEquals(queue.peek(), 1);
        assertEquals(queue.size(), 3);

        var y = queue.poll();
        assertEquals(y, 2);
        assertNotEquals(queue.peek(), 2);
        assertEquals(queue.size(), 2);
    }

    @Test
    void removeEmpty_ReturnsNull() {
        var queue = new Queue<Integer>();
        assertEquals(queue.size(), 0);
        assertNull(queue.remove());
    }

    @Test
    void removeNonEmpty_RetrieveAndRemovesHead() {
        var queue = new Queue<Integer>();
        queue.add(1);
        queue.add(2);
        queue.add(3);
        queue.add(4);
        assertEquals(queue.size(), 4);

        var x = queue.remove();
        assertEquals(x, 1);
        assertNotEquals(queue.peek(), 1);
        assertEquals(queue.size(), 3);

        var y = queue.remove();
        assertEquals(y, 2);
        assertNotEquals(queue.peek(), 2);
        assertEquals(queue.size(), 2);
    }
}
