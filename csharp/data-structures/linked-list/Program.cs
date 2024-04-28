// See https://aka.ms/new-console-template for more information
using System;
using System.Diagnostics;

namespace DS_LinkedList;

public class Program
{
    public static void Main(string[] args)
    {
        // Creating a data structure
        var ll = new LinkedList<string>();
        Debug.Assert(ll != null,
                "Linked list is null");
        Debug.Assert(ll.GetFirst() == null,
                "The first elem is not null on create");

        // Insert the first elem into the new linked list
        ll.Add("foo");
        Debug.Assert(ll.GetSize() == 1,
                "The size is not 1 after add");
        Debug.Assert(string.Equals(ll.GetFirst(), "foo"),
                "The first elem is not returning the value as expected");

        // Add 4 extra elemenst
        ll.Add("bar");
        ll.Add("baz");
        ll.Add("buz");
        ll.Add("buzzer");
        Debug.Assert(ll.GetSize() == 5,
                "Size not increased as expected");

        // Print list and check if it remains the same
        ll.PrintList();
        Debug.Assert(ll.GetSize() == 5,
                "Size not the same after print");
        Debug.Assert(string.Equals(ll.GetFirst(), "foo"),
                "The first elem is no longer the one with \"foo\" value");

        // Remove first elem added
        ll.Remove();
        Debug.Assert(ll.GetSize() < 5,
                "The list size was not decreased");
        Debug.Assert(!string.Equals(ll.GetFirst(), "foo"),
                "The list first elem still has the \"foo\" value");

        // Print list after first 2 elem removed
        ll.Remove();
        Debug.Assert(ll.GetSize() < 4,
                "The list size was not decreased for the second remove");
        Debug.Assert(string.Equals(ll.GetFirst(), "baz"),
                "The first elem (head) does not have the \"baz\" value");
        ll.PrintList();

        // Call Remove 4 times in a 3 elem list and print on a empty list
        ll.Remove();
        ll.Remove();
        ll.Remove();
        ll.Remove();
        Debug.Assert(ll.GetSize() == 0,
                "This list size is not zero as expected");
        Debug.Assert(ll.GetFirst() == null,
                "The empty list first is not null as it should be");
        ll.PrintList();
    }
}

