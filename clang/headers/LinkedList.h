#ifndef LINKED_LIST_HEADER
#define LINKED_LIST_HEADER

#include <stddef.h>

// LINKED LIST
//
// methods:
//     llist_append_node
//     llist_add_node_at
//     llist_find_node_by_index
//     llist_find_node_by_value
//     llist_delete_node_by_index
//     llist_delete_node_by_value
//     llist_print_list
//     llist_free_list


typedef struct Linked_List_Node {
    char * value;
    struct Linked_List_Node * next;
} Linked_List_Node;

typedef struct Linked_List {
    Linked_List_Node * first;
    size_t size;
} Linked_List;

Linked_List * llist_create_list();

void llist_append_node(Linked_List * list, const char * value);
void llist_add_node_at(Linked_List * list, const char * value, const size_t index);
Linked_List_Node * llist_find_node_by_index(const Linked_List * list, const size_t index);
Linked_List_Node * llist_find_node_by_value(const Linked_List * list, const char * value);
void llist_delete_node_by_index(Linked_List * list, const size_t index);
void llist_delete_node_by_value(Linked_List * list, const char * value);
void llist_free_nodes(Linked_List * list);
void llist_print_nodes(const Linked_List * list);
void llist_print_node(const Linked_List_Node * node);
void llist_print_node_with_index(const Linked_List_Node * node, const size_t index);

#endif // LINKED_LIST_HEADER
