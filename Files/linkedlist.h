#ifndef LINKLIST_H
#define LINKLIST_H
#include<stdlib.h>
#include<stdio.h>

//type definitions (used in all functions)
typedef int DATA;

typedef struct node
{
	struct node* right;
	struct node* left;
	DATA digit; /* a digit of a number range 0-9*/
}NODE;

typedef struct
{
	struct node* head; /* the head of the list */
	int size; /* number of elements in the list */
}LIST_HEAD;

void empty_list(LIST_HEAD* list);
void delete_list(LIST_HEAD* list);
LIST_HEAD *create_list(void);
NODE* insert_first(LIST_HEAD* list, DATA digit);
NODE* insert_at_end(LIST_HEAD* list,DATA digit);
void print_list(const LIST_HEAD *list);
void read(LIST_HEAD *list);
LIST_HEAD* reverse_list(LIST_HEAD* list);
#endif

