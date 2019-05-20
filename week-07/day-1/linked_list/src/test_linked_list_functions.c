//
// Created by Nico on 20/05/2019.
//

#include "test_linked_list_functions.h"

void append_at_end(list_t *head, int data)
{
    list_t *new_node = (list_t *) malloc(sizeof(list_t));
    new_node->data = data;
    new_node->next = NULL;
    list_t *it = head;
    while (it->next != NULL) {
        it = it->next;
    }
    it->next = new_node;
}

void append_at_beginning(list_t *head, int data)
{
    list_t *new_node = (list_t *) malloc(sizeof(list_t));
    new_node->data = data;
    new_node->next = head->next;
    head->next = new_node;
}