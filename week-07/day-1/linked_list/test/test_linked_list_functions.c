//
// Created by Nico on 20/05/2019.
//
#include "test_linked_list_functions.h"
#include ""
#include "../vendor/ceedling/vendor/unity/src/unity.h"


void test_append_at_beginning(void)
{
    list_t *head = (list_t *) malloc(sizeof(list_t));
    head->data = 0;
    head->next = NULL;

    append_at_beginning(head, 3);
    TEST_ASSERT_EQUAL(3, head->next->data);
}
