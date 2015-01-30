#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "linkedlist.h"

//creating a list
LIST_HEAD *create_list(void)
{
	LIST_HEAD *head_ptr = (LIST_HEAD*)malloc(sizeof(LIST_HEAD)); //create list head by allocation of memory
	if(head_ptr)
	{ //if created, then...
		head_ptr->head = 0; //point it to nothing
		head_ptr->size = 0; //make size=0
	}
  	return head_ptr;
}
void read(LIST_HEAD* list)
{
	int i,k;
	char n[100];
	printf("Enter a number now\n");
	scanf("%s",n);
	struct node* inptr;
    inptr = (struct node*)malloc(sizeof(struct node));
	for (i = 0;i < strlen(n); ++i)
	{
		 k = n[i]-48;
         	inptr = insert_first(list,k);
    }
	printf("The entered number in the given linkedlist is: ");
	print_list(list);
}



//emptying a list
void empty_list(LIST_HEAD *list)
{
  	NODE *prev, *pres;
 	pres = list->head;
	//prev=NULL;
 	 while(pres)
	{
		prev = pres;
        pres = pres->right;
	//	pres->left = NULL;
        free(prev);
  	}
  	list->size = 0;
  	list->head = 0;
}

//deleting a list
void delete_list(LIST_HEAD *list)
{
  	empty_list(list); //empty as before
  	free(list); //and free the memory allocated
}

//printing a list
void print_list(const LIST_HEAD *list)
{
	struct node *temp;
	temp = list->head;
	while(temp != NULL)
	{ //print every node's digit value until end of list
		printf("%d", temp->digit);
		temp = temp->right;
	}
  	printf("\n");
}

//insert node with given digit as first
NODE* insert_first(LIST_HEAD *list, DATA digit)
{
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	if(!newnode)
		return NULL; //in case memory allocation failed
	newnode->right = NULL;
	newnode->left = NULL;
	newnode->digit = digit;
	if(list->head == 0)
	{
		list->head=newnode;
		(list->size)++;
	}
	else
	{
        	newnode->right = list->head;
        	list->head->left = newnode;
        	list->head = newnode;
        	(list->size)++;
	}
	return newnode;
}

NODE* insert_at_end(LIST_HEAD* list,DATA digit)
{
        NODE* newnode;
        NODE* p;
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->digit = digit;
        newnode->left = NULL;
        newnode->right = NULL;
        if(list->head == NULL)
        {
                list->head = newnode;
        }
        else
        {
        	p = list->head;
        	while(p->right != NULL)
        	{
        	        p = p->right;
        	}
        	p->right = newnode;
        	newnode->left = p;
        }
        return(newnode);
}
LIST_HEAD* reverse_list(LIST_HEAD* list)
{
	NODE *prev, *next, *curr;
	prev = list->head;
	if(prev)
	{
		curr = prev->right;
		prev->right = NULL;
	}
	while(curr)
	{
		next = curr->right;
		curr->right = prev;
		prev = curr;
		curr = next;
	}
	list->head = prev;
	return list;
}
	
