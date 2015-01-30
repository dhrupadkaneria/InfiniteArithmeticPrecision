#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "linkedlist.h"
#include "number.h"

int main(void)
{
	char ch;
	LIST_HEAD *number1 = create_list();
	LIST_HEAD *number2 = create_list();
	int d, option, i, size, c;
	char n[100];
	while (1)
	{
		printf("\n");
		printf("1. Insert first number\n");
        printf("2. Insert second number\n");
        printf("3. Add numbers\n");
		printf("4. Multiply numbers\n");
		printf("5. Factorial\n");
		printf("6. Exit\n");
        printf("Enter option: ");
		scanf("%d",&option);
		switch(option)
		{
		case 1:
                	empty_list(number1);
                	read(number1);
                	break;
		case 2:
                	empty_list(number2);
                	read(number2);
                	break;
		case 3: 
			printf("\nThe result of adding two numbers is: ");
 			//if number1 or number2 is emptylist, make it the list containing zero only
			if (number1 == NULL)
				insert_first(number1, 0);
			if (number2 == NULL)
				insert_first(number2, 0);
 			//create list of result and print it
			LIST_HEAD *numplusnum = create_list();
			numplusnum = add_two_numbers(number1,number2);
			print_list(numplusnum);
			break;
		case 4: 
			printf("\nThe result of multiplying two numbers is: ");
			//if number1 or number2 is emptylist, make it the list containing zero only
                        if (number1 == NULL)
                                insert_first(number1, 0);
                        if (number2 == NULL)
                                insert_first(number2, 0);
                        //create list of result and print it
                        LIST_HEAD *numprodnum = create_list();
                        numprodnum = multiply_two_numbers(number1,number2);
                        print_list(numprodnum);
                        break;
		case 5: 
			printf("Enter the value whose factorial is to be found: ");
			scanf("%d",&c);
			if(c < 0)
				printf("The factorial connot be found.\n");
			else
			{
				LIST_HEAD *fvalue = create_list();
				fvalue = factorial(c);
				printf("The factorial is: ");
				print_list(fvalue);
			}
			break;
		case 6: 
			printf("Good bye, TATA!!!..\n\n\n");
                	exit(0);
		default: 
			printf("Invalid option.\n");
                	break;
		}

	}
	return 0;
}
