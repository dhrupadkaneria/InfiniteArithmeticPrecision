#ifndef NUMBER_H
#define NUMBER_H
#include<stdlib.h>
#include<stdio.h>
 
void add_two_digits(int d1, int d2, int carry_in, int * result, int *carry_out);
LIST_HEAD *add_two_numbers (const LIST_HEAD *n1, const LIST_HEAD *n2);
LIST_HEAD *multiply_number_digit(LIST_HEAD *N1, int digit);
void multiply_two_digits(int d1, int d2, int carry_in, int *result, int *carry_out);
LIST_HEAD * multiply_two_numbers (LIST_HEAD *n1, LIST_HEAD *n2);
LIST_HEAD *multiply_number_by_10(LIST_HEAD *n);
LIST_HEAD *factorial(int n);
#endif 
