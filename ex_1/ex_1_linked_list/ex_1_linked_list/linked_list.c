#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node {
	int data;
	struct node * next;
} node_t;

void free_list(node_t * head) {
	node_t * current = head;
	while (current != NULL)
	{
		node_t * temp_node = current;
		current = current->next;
		free(temp_node);
	}
}

node_t * add_end(node_t * head , int data) {
	if (head == NULL) {
		head = (node_t*)malloc(sizeof(node_t));
		head->data = data;
		head->next = NULL;
	}
	else {
		node_t * current = head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = (node_t*)malloc(sizeof(node_t));
		current->next->data = data;
		current->next->next = NULL;
	}
	return head;
}

node_t * add_start(node_t ** head, int data) {
	if (*head != NULL) {
		node_t * new_node = (node_t*)malloc(sizeof(node_t));
		new_node->data = data;
		new_node->next = *head;
		*head = new_node;
	}
	else {
		*head = add_end(*head, data);
	}
	return *head;
}

node_t * add_after(node_t * head, int existing_element, int new_element) {
	if (head != NULL) {
		node_t * current = head;
		while (current != NULL) {
			if (current->data == existing_element) {
				node_t * new_node = (node_t*)malloc(sizeof(node_t));
				new_node->data = new_element;
				new_node->next = current->next;
				current->next = new_node;
				return head;
			}
			current = current->next;
		}
	}
	printf("Element %d could not be found\n", existing_element);
	free_list(head);
	exit(0);
}

void index(node_t* head, int wanted_element) {
	if (head != NULL) {
		int current_index = 0;
		node_t * current = head;
		while (current != NULL) {
			if (current->data == wanted_element) {
				printf("Element %d is found in index %d\n", wanted_element, current_index);
				return;
			}
			current_index += 1;
			current = current->next;
		}
	}
	printf("Element %d isn't in the list, index -1\n", wanted_element);
}

node_t * del_index(node_t** head, int index) {
	if (*head != NULL) {
		int current_index = 0;
		node_t * current = *head;
		node_t * temp_pointer = NULL;
		while (current_index < index - 1) {
			if (current->next == NULL) {
				printf("Index is too large\n");
				free_list(*head);
				exit(0);
			}
			current_index += 1;
			current = current->next;
		}
		if (current->next == NULL) {
			printf("Index is too large\n");
			free_list(*head);
			exit(0);
		}

		temp_pointer = current->next;
		current->next = temp_pointer->next;
		free(temp_pointer);
		return *head;
	}
}

void print_list(node_t * head) {
	if (head == NULL) {
		printf("[]\n");
	}
	else {
		node_t * current = head;
		printf("[");
		while (current != NULL) {
			if (current->next == NULL) {
				printf("%d", current->data);
			}
			else {
				printf("%d, ", current->data);
			}
			current = current->next;
		}
		printf("]\n");
	}
}
