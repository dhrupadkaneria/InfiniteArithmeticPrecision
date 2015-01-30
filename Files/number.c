#include<stdlib.h>
#include<stdio.h>
#include "linkedlist.h"
#include "number.h"

//add two digits
void add_two_digits(int d1, int d2, int carry_in, int * result, int *carry_out)
{
	*result = d1+d2+carry_in;
	if (*result >= 10)
	{
		*result = *result-10;
		*carry_out = 1;
	}
	else
		*carry_out = 0;
}

//add two numbers
LIST_HEAD *add_two_numbers (const LIST_HEAD *n1, const LIST_HEAD *n2)
{
	struct node *p1;

	struct node *p2;

 	int temp = 0; //temp integer to store a result of adding
	int carry_in = 0; //carry_in value, local
	int carry_out = 0; //carry_out value, global, goes as adress to add_two_digits function
 	p1 = n1->head; //let p1 point to the beginning of first number list
	p2 = n2->head; //and p2 - to the second
	LIST_HEAD *result = (LIST_HEAD*)malloc(sizeof(LIST_HEAD)); //this is result list
 	if(result)
	{
    		result->head = 0; //if created succesfully - make head point to nothing
    		result->size = 0; //and size is zero
	}
 	while (p1 != NULL && p2 != NULL)
	{ //add every two digits in lists until one list is finished
		carry_in = carry_out; //carry_in is equal to carry_out from previous operation
		add_two_digits(p1->digit, p2->digit, carry_in, &temp, &carry_out);
		insert_first(result, temp); //add one node to the beginning of the list with the result of adding
		p1 = p1->right;
		p2 = p2->right;
	}
 	//make new node and point it to continuing of p1 OR p2 OR nothing
	struct node *p;
	p = (struct node*)malloc(sizeof(struct node));
	if (p1 == NULL)
		p = p2;
	else
		p = p1;
 	//and now add every digit from the rest with zeros
	while (p != NULL)
	{
		carry_in = carry_out;
		add_two_digits(p->digit, 0, carry_in, &temp, &carry_out);
		insert_first(result, temp); //add one node to the beginning of the list with the result of adding
		p = p->right;
	}
 	//if there's carry_out left, add it as digit to list
	if (p == NULL && carry_out != 0)
		insert_first(result, carry_out);
	return result;
}

//multiplying number as LIST_HEAD with digit
LIST_HEAD *multiply_number_digit(LIST_HEAD *N1, int digit)
{
	struct node *p1;
	int temp = 0; //temp integer to store a result of adding
	int carry_in = 0; 
	int carry_out = 0;
 	p1 = (struct node*)malloc(sizeof(struct node));
	p1 = N1->head; //let p1 point to the beginning of first number list
	LIST_HEAD *result = create_list();
 	while (p1 != NULL)
	{ //multiply number by digit until list is finished
		carry_in = carry_out;
		multiply_two_digits(p1->digit, digit, carry_in, &temp, &carry_out);
		insert_first(result, temp);//add one node to the beginning of the list with the result of adding
		p1 = p1->right;
	}	
	//if there's carry_out left, add it as digit to list
	if (p1 == NULL && carry_out != 0) 
		insert_first(result, carry_out);
	return result;
}
 
//multiplying two digits
void multiply_two_digits(int d1, int d2, int carry_in, int *result, int *carry_out)
{
	if((*result = d1 * d2 + carry_in) >= 10)
	{
    		*carry_out = *result/10;
    		*result = *result%10;
  	} 
	else 
		*carry_out = 0;
}
 
//multiplying two numbers
LIST_HEAD *multiply_two_numbers (LIST_HEAD *n1, LIST_HEAD *n2)
{
	struct node *p1;
	struct node *p2;
	p1 = n1->head; //let p1 point to the beginning of first number list
	p2 = n2->head; //and p2 - to the second
 	LIST_HEAD *result = create_list(); //list for full result
	LIST_HEAD *stepresult = create_list(); //list for step result
 	int x = 0; //this is variable showing how many times should we multiply stepresult by 10
	int count = 0; //this is counter for multiplying_by_10 loop
 	while (p1 != NULL)
	{ //work until end of list
		count = 0; //initial count is zero
		empty_list(stepresult); //empty previous stepresult
		stepresult = multiply_number_digit(n2, p1->digit); //multiply second list by first digit of first list
		while (count < x)
		{	
			stepresult = multiply_number_by_10(stepresult);
			count++;
		} //and multiply it by 10x or 1 if needed

		//to add two numbers i.e result and step result
		//both the lists should be given in reverse order
		//for the first time, we directly get the stepresult in reverse order
		//hence in the consecutive steps we need to reverse the stepresult
		if(x != 0)
			reverse_list(stepresult);
		//the result in the first step is null, hence no problem
		//the result after second step is already reversed, so no need to reverse
		//the result in the consecutive steps is in the order, but to add it with stepresult
			//we need to reverse it and add
		if(count > 1)
			reverse_list(result);
		result = add_two_numbers(result, stepresult); //add stepresult to result
		x++;//next time - multiply by 10 one more time (shifting)
		p1 = p1->right;
	}
	if(n1->size == 1)//reverse the result if the first number is single digit
	{
		reverse_list(result);
	}
	return result;
}
 
//multiplying number by 10
LIST_HEAD *multiply_number_by_10(LIST_HEAD *n)
{
	LIST_HEAD *result = create_list();
	result->head = n->head;
	insert_at_end(result, 0); //just add 0 as first node in a list
	return result;
}


LIST_HEAD *factorial(int n)
{
	int i;
	LIST_HEAD *temp1 = create_list();//create a pointer to list temp1
        LIST_HEAD *result = create_list();//create a pointer to list result
	LIST_HEAD *temp = create_list();// create a pointer to list temp (which stores 1)
        insert_first(result, 1);//initialize result to 1
	insert_first(temp, 1);// initialize temp to 1
	insert_first(temp1, 1);//initialize temp1 to 1
	for(i = 1; i < n; ++i)
	{
		temp1 = add_two_numbers(temp1, temp);//add 1 to the prevous count
		reverse_list(temp1);
		reverse_list(result);
		result = multiply_two_numbers(result, temp1);//multiply the previous result by the count
	}
	return result;
}
