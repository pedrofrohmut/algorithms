#ifndef LINKED_LIST_HEADER
#define LINKED_LIST_HEADER

#include <stddef.h>

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


typedef struct Linked_List_Node {
    const char * value;
    struct Linked_List_Node * next;
} Linked_List_Node;

typedef struct Linked_List {
    Linked_List_Node * first;
    size_t size;
} Linked_List;

Linked_List * create_list();

void append_node(Linked_List * list, const char * value);
void add_node_at(Linked_List * list, const char * value, const size_t index);
Linked_List_Node * find_node_by_index(const Linked_List * list, const size_t index);
Linked_List_Node * find_node_by_value(const Linked_List * list, const char * value);
void delete_node_by_index(Linked_List * list, const size_t index);
void delete_node_by_value(Linked_List * list, const char * value);
void free_nodes(Linked_List * list);
void print_nodes(const Linked_List * list);
void print_node(const Linked_List_Node * node);
void print_node_with_index(const Linked_List_Node * node, const size_t index);

#endif // LINKED_LIST_HEADER
