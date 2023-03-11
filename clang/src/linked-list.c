#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// LINKED LIST
//
// methods:
//     append_node
//     add_node_at
//     find_node_by_index
//     find_node_by_value
//     delete_node_by_index
//     delete_node_by_value
//     print_list
//     free_list
#include "../headers/LinkedList.h"


int main()
{
    // Init List
    Linked_List * list = create_list();

    // Populate
    append_node(list, "Once");
    append_node(list, "Upon");
    append_node(list, "a");
    append_node(list, "Time");

    // Print before
    printf("\n> List Before\n");
    print_nodes(list);

    // Find by index
    printf("\n> Linked_List_Nodes At\n");
    Linked_List_Node * node1 = find_node_by_index(list, 0);
    print_node_with_index(node1, 0);
    Linked_List_Node * node2 = find_node_by_index(list, 1);
    print_node_with_index(node2, 1);
    Linked_List_Node * node3 = find_node_by_index(list, 2);
    print_node_with_index(node3, 2);
    Linked_List_Node * node4 = find_node_by_index(list, 3);
    print_node_with_index(node4, 3);
    Linked_List_Node * node5 = find_node_by_index(list, 4);
    print_node_with_index(node5, 4);
    Linked_List_Node * node6 = find_node_by_index(list, 5);
    print_node_with_index(node6, 5);

    // Search (Find by value)
    printf("\n> Search (find node by value)\n");
    Linked_List_Node * timeLinked_List_Node = find_node_by_value(list, "Time");
    printf("Found node with 'Time'? %s\n", timeLinked_List_Node != NULL ? "Yes" : "No");
    Linked_List_Node * fooLinked_List_Node = find_node_by_value(list, "Foo");
    printf("Found node with 'Foo'? %s\n", fooLinked_List_Node != NULL ? "Yes" : "No");

    // Add node at index. Using VIRUS to be easy to spot
    printf("\n> Add Linked_List_Node At\n");
    add_node_at(list, "FIRST_VIRUS", 0);
    add_node_at(list, "ME_VIRUS", 2);
    add_node_at(list, "LAST_VIRUS", 6);
    add_node_at(list, "OUT_OF_BOUNDS_VIRUS", 666);

    // Print list after new aditions
    printf("\n> List after aditions\n");
    print_nodes(list);

    // Delete by value
    printf("\n> Delete By Value\n");
    delete_node_by_value(list, "ME_VIRUS");
    delete_node_by_value(list, "FIRST_VIRUS"); // Checked edge case first
    delete_node_by_value(list, "LAST_VIRUS"); // Checked edge case last

    // Print list after removal
    printf("\n> List After VIRUS of Removal\n");
    print_nodes(list);

    // Delete by index
    printf("\n> Delete By Index\n");
    delete_node_by_index(list, 0); // removes 'Once'
    delete_node_by_index(list, 2); // removes 'Time'
    delete_node_by_index(list, 0); // removes 'Upon'

    // Print list after removal
    printf("\n> List After Delete by_index 2\n");
    print_nodes(list); // prints 'a'

    printf("\n> Free List\n");
    free_nodes(list);

    free(list);

    return 0;
}
