#include <stdio.h>
#include <stdlib.h>

typedef struct list_t
{
    int data;
    struct list_t *next;
} list_t;

void append_at_end(list_t *head, int data);

void append_at_beginning(list_t *head, int data);

void append_after_x(list_t *head, int x, int data);

int count_my_list(list_t *head);

int is_it_empty(list_t *head);

list_t *delete_first_element(list_t *head);

void delete_by_value(list_t *head, int value);

list_t *search_by_value(list_t *head, int value);

int main()
{
    list_t *head = (list_t *) malloc(sizeof(list_t));
    head->data = 0;
    head->next = NULL;

    printf("%s\n", is_it_empty(head) ? "My list is empty..." : "My list is not empty!");
    append_at_beginning(head, 3);
    append_at_end(head, 5);
    append_at_beginning(head, 7);
    list_t *iterator = head;
    for (; iterator != NULL; iterator = iterator->next) {
        printf("%d\n", iterator->data);
    }
    append_after_x(head, 3, 8);
    for (iterator = head; iterator != NULL; iterator = iterator->next) {
        printf("%d\n", iterator->data);
    }
    printf("My list is so big, it holds %d nodes!\n", count_my_list(head));

    printf("%s\n", is_it_empty(head) ? "My list is empty..." : "My list is not empty!");

    delete_first_element(head);

    for (iterator = head; iterator != NULL; iterator = iterator->next) {
        printf("%d\n", iterator->data);
    }
    printf("My list is so big, it holds %d nodes!\n", count_my_list(head));

    append_at_end(head, 4);

    append_at_end(head, 2);

    for (iterator = head; iterator != NULL; iterator = iterator->next) {
        printf("%d\n", iterator->data);
    }
    printf("My list is so big, it holds %d nodes!\n", count_my_list(head));

    delete_by_value(head, 4);

    for (iterator = head; iterator != NULL; iterator = iterator->next) {
        printf("%d\n", iterator->data);
    }
    printf("My list is so big, it holds %d nodes!\n", count_my_list(head));

    printf("The value %d in my list is found at the address: %p.", 5, search_by_value(head, 5));

    return 0;
}

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

void append_after_x(list_t *head, int x, int data)
{
    list_t *new_node = (list_t *) malloc(sizeof(list_t));
    new_node->data = data;
    list_t *it = head;
    while (it->data != x) {
        it = it->next;
    }
    new_node->next = it->next;
    it->next = new_node;
}

int count_my_list(list_t *head)
{
    list_t *itr = head;
    int counter = 0;
    for (; itr != NULL; itr = itr->next) {
        counter++;
    }
    return counter - 1;
}

int is_it_empty(list_t *head)
{
    list_t *itr = head;
    int counter = 0;
    for (; itr != NULL; itr = itr->next) {
        counter++;
    }
    if (counter > 1) {
        return 0;
    } else return 1;
}

list_t *delete_first_element(list_t *head)
{
    list_t *temporary = head->next->next;
    free(head->next);
    head->next = temporary;
}

void delete_by_value(list_t *head, int value)
{
    list_t *iterator = head;
    for (; iterator != NULL; iterator = iterator->next) {
        if (iterator->data == value) {
            iterator->data = iterator->next->data;
            list_t *temporary = iterator->next->next;
            free(iterator->next);
            iterator->next = temporary;
        }
    }
}

list_t *search_by_value(list_t *head, int value)
{
    list_t *iterator = head;
    for (; iterator->next->data != '\0'; iterator = iterator->next) {
        if (iterator->next->data == value){
            return iterator->next;
        }
    }
    return NULL;
}