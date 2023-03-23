#include "../headers/BinaryTree.h"

#include <stdio.h>
#include <stdlib.h>

Binary_Tree * btree_create_tree()
{
    Binary_Tree * new_tree = malloc(sizeof(Binary_Tree));
    new_tree->root = NULL;
    new_tree->size = 0;
    return new_tree;
}

size_t btree_size(const Binary_Tree * tree) { return tree->size; }

Binary_Tree_Node * _prepare_new_node(const size_t value)
{
    Binary_Tree_Node * new_node = malloc(sizeof(Binary_Tree_Node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void btree_add_node(Binary_Tree * tree, const size_t value)
{
    Binary_Tree_Node * new_node = _prepare_new_node(value);

    tree->size++;

    if (tree->root == NULL) {
        tree->root = new_node;
        return;
    }

    Binary_Tree_Node * before = NULL;
    Binary_Tree_Node * iterator = tree->root;

    // Find suitable position
    while (iterator != NULL) {
        before = iterator;
        if (value < iterator->value) {
            iterator = iterator->left;
        } else {
            iterator = iterator->right;
        }
    }

    if (value < before->value) {
        before->left = new_node;
    } else {
        before->right = new_node;
    }
}

Binary_Tree_Node * btree_find_node(const Binary_Tree * tree, const size_t value)
{
    Binary_Tree_Node * iterator = tree->root;
    while(iterator != NULL) {
        if (iterator->value == value) return iterator;
        if (value < iterator->value) {
            iterator = iterator->left;
        } else {
            iterator = iterator->right;
        }
    }
    return NULL;
}

// Root Case - Delete it, give the position to successor and setup hanging child
void _resolve_root_case(Binary_Tree * tree,
                        Binary_Tree_Node * before_del_pos,
                        Binary_Tree_Node * delete_position)
{
    // Find the successor node
    Binary_Tree_Node * before_successor = delete_position;
    Binary_Tree_Node * successor = delete_position->right;
    while (successor->left != NULL) {
        before_successor = successor;
        successor = successor->left;
    }

    Binary_Tree_Node * old_root = tree->root;
    Binary_Tree_Node * hanging_child = successor->right;

    // Set successor as new root
    successor->left = tree->root->left;
    successor->right = tree->root->right;
    tree->root = successor;

    // Set hanging child new position
    before_successor->left = hanging_child;

    free(old_root);
}

// Has no children - Just delete it
void _resolve_no_children_case(Binary_Tree_Node * before, Binary_Tree_Node * iterator)
{
    if (before->left == iterator) {
        before->left = NULL;
    } else {
        before->right = NULL;
    }

    free(iterator);
}

// Has two children - Delete it, given the old position to the successor child and setup hanging child
void _resolve_two_children_case(Binary_Tree_Node * before_del_pos,
                                Binary_Tree_Node * delete_position)
{
    // Find Successor
    Binary_Tree_Node * before_successor = delete_position;
    Binary_Tree_Node * successor = delete_position->right;
    while (successor->left != NULL) {
        before_successor = successor;
        successor = successor->left;
    }

    Binary_Tree_Node * hanging_child = successor->right;

    // Setup left and right for successor
    successor->left = delete_position->left;
    if (delete_position->right == successor) {
        successor->right = NULL;
    } else {
        successor->right = delete_position->right;
    }

    // Update before delete position point to successor
    if (before_del_pos->left == delete_position) {
        before_del_pos->left = successor;
    } else {
        before_del_pos->right = successor;
    }

    // Set hanging child new position
    if (before_successor == delete_position) { // 56
        successor->right = hanging_child;
    } else { // 75
        before_successor->left = hanging_child;
    }

    free(delete_position);
}

// Has only one child - Delete it and give the old position to the child
void _resolve_single_child_case(Binary_Tree_Node * before, Binary_Tree_Node * iterator)
{
    Binary_Tree_Node * child = iterator-> left != NULL ? iterator->left : iterator->right;

    if (before->left == iterator) {
        before->left = child;
    } else {
        before->right = child;
    }

    free(iterator);
}

void btree_delete_node(Binary_Tree * tree, const size_t value)
{
    if (tree->root == NULL) return;

    Binary_Tree_Node * before = NULL;
    Binary_Tree_Node * iterator = tree->root;

    while (iterator != NULL) {
        if (iterator->value == value) break;
        before = iterator;
        if (value < iterator->value) {
            iterator = iterator->left;
        } else {
            iterator = iterator->right;
        }
    }

    // Not Found
    if (iterator == NULL) return;

    if (before == NULL) {
        _resolve_root_case(tree, before, iterator);
        return;
    }

    if (iterator->left == NULL && iterator->right == NULL) {
        _resolve_no_children_case(before, iterator);
        return;
    }

    if (iterator->left != NULL && iterator->right != NULL) {
        _resolve_two_children_case(before, iterator);
        return;
    }

    _resolve_single_child_case(before, iterator);
}

void _recursively_free_node(Binary_Tree_Node * node)
{
    if (node == NULL) return;

    _recursively_free_node(node->left);
    _recursively_free_node(node->right);

    /* printf("Debug: Freeing Node with value: %zu\n", node->value); */
    free(node);
}

void btree_free_nodes(Binary_Tree * tree)
{
    _recursively_free_node(tree->root);
}

size_t g_counter = 0;
void _recursively_print_node(const Binary_Tree_Node * node)
{
    if (node == NULL) return;
    printf("[%zu] = %zu\n", g_counter, node->value);
    g_counter++; // Use of global here to avoid pointless complexity
    _recursively_print_node(node->left);
    _recursively_print_node(node->right);
}

void btree_print_tree(const Binary_Tree * tree)
{
    if (tree->root == NULL) {
        printf("The tree is empty\n");
        return;
    }
    g_counter = 0;
    _recursively_print_node(tree->root);
}

void btree_debug_node(const Binary_Tree_Node * node)
{
    if (node == NULL) {
        printf("Debug: Node is NULL\n");
    } else {
        printf("Debug: Value = %zu\n", node->value);
    }
}

void _recursively_debug_tree(const Binary_Tree_Node * node)
{
    if (node == NULL) return;

    btree_debug_node(node);

    _recursively_debug_tree(node->left);
    _recursively_debug_tree(node->right);
}

void btree_debug_tree(const Binary_Tree * tree)
{
    _recursively_debug_tree(tree->root);
}
