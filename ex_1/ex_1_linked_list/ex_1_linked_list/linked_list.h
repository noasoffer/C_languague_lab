#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node {
	int data;
	struct node * next;
} node_t;

node_t * add_end(node_t * head, int data);

node_t * add_start(node_t ** head, int data);

node_t * add_after(node_t * head, int existing_element, int new_element);

void index(node_t* head, int wanted_element);

node_t * del_index(node_t** head, int index);

void print_list(node_t * head);

void free_list(node_t * head);

#endif //LINKED_LIST_H