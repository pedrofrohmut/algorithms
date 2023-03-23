#include <stdio.h>
#include <stdlib.h>

#include "../headers/BinaryTree.h"

/*                     50
               ________|_________
              |                 |
             25                75
         ____|____         ____|____
        |        |        |        |
       10       33       56       89
     __|__    __|__    __|__    __|__
    |    |   |    |   |    |   |    |
    4   11  30   40  52   61  82   95
                      |_   |_  |_
                        |   |   |
                       55  69  87
                      /    |    \
hanging child for root     |     \
                          /       \
       hanging child for 56       hanging child for 75 del
   */
int main()
{

    Binary_Tree * tree = btree_create_tree();

    printf("\n> Add nodes\n");

    // First level
    btree_add_node(tree, 50);

    // Second level
    btree_add_node(tree, 25);
    btree_add_node(tree, 75);

    // Third level
    btree_add_node(tree, 10);
    btree_add_node(tree, 33);
    btree_add_node(tree, 56);
    btree_add_node(tree, 89);

    // Forth level
    btree_add_node(tree, 4);
    btree_add_node(tree, 11);
    btree_add_node(tree, 30);
    btree_add_node(tree, 40);
    btree_add_node(tree, 52);
    btree_add_node(tree, 61);
    btree_add_node(tree, 82);
    btree_add_node(tree, 95);

    // Fifth level - Hanging children for testing
    btree_add_node(tree, 55);
    btree_add_node(tree, 69);
    btree_add_node(tree, 87);

    printf("\n> Print Tree Nodes (Initial, Size = %zu)\n", btree_size(tree));
    btree_print_tree(tree);

    // Find nodes in the tree
    printf("\n> Find nodes\n");
    Binary_Tree_Node * result_33 = btree_find_node(tree, 33);
    btree_debug_node(result_33);
    Binary_Tree_Node * result_666 = btree_find_node(tree, 666);
    btree_debug_node(result_666);

    // Delete the edge cases 666, 4, 10, 56, 75, 50
    printf("\n> Delete nodes\n");
    btree_delete_node(tree, 666); // Not Found
    btree_delete_node(tree, 4);  // No children
    btree_delete_node(tree, 10); // Single child
    btree_delete_node(tree, 56); // Two children
    btree_delete_node(tree, 75); // Two children higher level
    btree_delete_node(tree, 50); // Tree root

    // Print after delete
    printf("\n> Print Tree after deletes (Size = %zu)\n", btree_size(tree));
    btree_print_tree(tree);

    // Free Node
    printf("\n> Free Nodes\n");
    btree_free_nodes(tree);

    free(tree);

    return 0;
}
