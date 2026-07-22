#ifndef BINARY_TREE_HEADER
#define BINARY_TREE_HEADER

#include <stddef.h>

// BINARY TREE
// methods:
//     btree_create_tree
//     btree_size
//     btree_print_tree
//     btree_debug_tree
//
//     btree_add_node
//     btree_find_node
//     btree_delete_node
//     btree_free_nodes
//     btree_debug_node

typedef struct Binary_Tree_Node {
    size_t value;
    struct Binary_Tree_Node * left;
    struct Binary_Tree_Node * right;
} Binary_Tree_Node;

typedef struct Binary_Tree {
    Binary_Tree_Node * root;
    size_t size;
} Binary_Tree;

Binary_Tree * btree_create_tree();
size_t btree_size(const Binary_Tree * tree);

void btree_add_node(Binary_Tree * tree, const size_t value);
Binary_Tree_Node * btree_find_node(const Binary_Tree * tree, const size_t value);
void btree_delete_node(Binary_Tree * tree, const size_t value);
void btree_free_nodes(Binary_Tree * tree);

void btree_print_tree(const Binary_Tree * tree);
void btree_debug_node(const Binary_Tree_Node * node);
void btree_debug_tree(const Binary_Tree * tree);

#endif // !BINARY_TREE_HEADER
