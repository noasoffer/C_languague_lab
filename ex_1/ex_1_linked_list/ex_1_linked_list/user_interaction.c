#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "linked_list.h"


#define MAX_INPUT_SIZE 100

void input_processing(char *str, int return_array[]) {
	for (int i = 0; i < strlen(str); ++i) {
		str[i] = tolower((unsigned char)str[i]);
	}
	char * command = strtok(str, " ");
	if (strstr(command,"add_end")) {
		return_array[0] = 0;
		return_array[1] = atoi(strtok(NULL, " "));
	}
	else if (strstr(command, "add_start")) {
		return_array[0] = 1;
		return_array[1] = atoi(strtok(NULL, " "));
	}
	else if (strstr(command, "add_after")) {
		return_array[0] = 2;
		return_array[1] = atoi(strtok(NULL, " "));
		return_array[2] = atoi(strtok(NULL, "/n"));
	}
	else if (strstr(command, "del_index")) {
		return_array[0] = 4;
		return_array[1] = atoi(strtok(NULL, " "));
	}
	else if (strstr(command, "index")) {
		return_array[0] = 3;
		return_array[1] = atoi(strtok(NULL, " "));
	}
	else if (strstr(command, "print")) {
		return_array[0] = 5;
	}
	else if (strstr(command, "exit")) {
		return_array[0] = 6;
	}
}

node_t* run_command(node_t * head, int command_num, int arg_0, int arg_1) {
	
	if (command_num == 0) {
		head = add_end(head, arg_0);
	}
	else if (command_num == 1) {
		head = add_start(& head, arg_0);
	}
	else if (command_num == 2) {
		head = add_after(head, arg_1, arg_0);
	}
	else if (command_num == 3) {
		index(head, arg_0);
	}
	else if (command_num == 4 ) {
		head = del_index(&head, arg_0);
	}
	else if (command_num == 5) {
		print_list(head);
	}
	else if (command_num == 6) {
		free_list(head);
		exit(0);
	}
	return head;
}

int main() {
	char input[MAX_INPUT_SIZE];
	node_t * head = NULL;
	int parse_args[3] = { 0 };
	while (scanf("%[^\n]%*c", input) == 1) {
		input_processing(input, parse_args);
		head = run_command(head,parse_args[0],parse_args[1],parse_args[2]);
	}
	return 0;
}