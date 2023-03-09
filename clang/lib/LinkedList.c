#include "../headers/LinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Linked_List * create_list()
{
    Linked_List * new_list = malloc(sizeof(Linked_List));
    new_list->first = NULL;
    new_list->size = 0;
    return new_list;
}

void append_node(Linked_List * list, const char * value)
{
    // Prepare new node
    Node * new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;

    list->size++;

    // If empty list
    if (list->first == NULL) {
        list->first = new_node;
    } else {
        // Go to last node
        Node * iterator = list->first;
        while (iterator->next != NULL) {
            iterator = iterator->next;
        }

        iterator->next = new_node;
    }
}

void add_node_at(Linked_List * list, const char * value, const size_t index)
{
    // Out of bounds
    if (index > list->size || index < 0) return;

    // Prepare new node
    Node * new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;

    list->size++;

    // Iterate until index
    Node * iterator = list->first;
    Node * before = NULL;
    size_t i = 0;
    while (i < index) {
        before = iterator;
        iterator = iterator->next;
        i++;
    }

    // Add node to list
    if (iterator == list->first) {
        new_node->next = list->first;
        list->first = new_node;
    } else {
        Node * temp = before->next;
        before->next = new_node;
        new_node->next = temp;
    }
}

Node * find_node_by_index(const Linked_List * list, const size_t index)
{
    // Out of bounds
    if (index > list->size - 1 || index < 0) return NULL;

    Node * iterator = list->first;
    size_t i = 0;

    // Iterate until index
    while (i < index) {
        iterator = iterator->next;
        i++;
    }

    return iterator;
}

Node * find_node_by_value(const Linked_List * list, const char * value)
{
    Node * iterator = list->first;

    // Iterate until found or last node
    while (iterator != NULL) {
        if (strcmp(iterator->value, value) == 0) return iterator;
        iterator = iterator->next;
    }

    return NULL;
}

void delete_node_by_index(Linked_List * list, const size_t index)
{
    // Out of bounds
    if (index > list->size || index < 0) return;

    Node * iterator = list->first;
    Node * before = NULL;
    size_t i = 0;

    // Iterate until the index
    while (i < index) {
        before = iterator;
        iterator = iterator->next;
        i++;
    }

    // Update pointers
    if (iterator == list->first) {
        list->first = iterator->next;
    } else {
        before->next = iterator->next;
    }

    free(iterator);
    list->size--;
}

void delete_node_by_value(Linked_List * list, const char * value)
{
    // Empty list
    if (list->first == NULL) return;

    Node * iterator = list->first;
    Node * before = NULL;

    // Iterate until found or last node
    while (iterator != NULL) {
        if (strcmp(iterator->value, value) == 0) break;
        before = iterator;
        iterator = iterator->next;
    }

    // Update pointers
    if (iterator == list->first) {
        list->first = iterator->next;
    } else {
        before->next = iterator->next;
    }

    free(iterator);
    list->size--;
}

void free_nodes(Linked_List * list)
{
    Node * iterator = list->first;
    size_t counter = 0;

    // Iterate until last node
    while (iterator != NULL) {
        Node * temp = iterator;
        iterator = iterator->next;

        // Debug message can be removed or commented out
        printf("[%zu] %s is Freed\n", counter, temp->value);

        counter++;
        free(temp);
    }

    // reset list
    list->first = NULL;
    list->size = 0;
}

void print_nodes(const Linked_List * list)
{
    Node * iterator = list->first;
    size_t counter = 0;

    // Iterate until last node
    while (iterator != NULL) {
        printf("[%zu] %s\n", counter, iterator->value);
        iterator = iterator->next;
        counter++;
    }
}

void print_node(const Node * node)
{
    const char * value = node == NULL ? "NULL" : node->value;
    printf("Node: %s\n", value);
}

void print_node_with_index(const Node * node, const size_t index)
{
    const char * value = node == NULL ? "NULL" : node->value;
    printf("Node %zu: %s\n", index, value);
}
