/*********************************************************************
 * FILE NAME: myProgram.c
 * PURPOSE: Test program for Student List implementations.
 * AUTHOR: P. Matsakis (CIS2520, Assignment 1)
 * DATE: 21/09/2015
 * NOTES: This program uses test data recorded in a text file
 *        (see test.txt). 
 *********************************************************************/


#include "StackInterface.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void print (Stack * S);
void add (Stack num1, Stack num2, Stack * result);

int main(void)
{
	FILE *test;
	
    int i = 0;
    int temp = 0;

    
    char string1[100];
    char string2[100];
    
	Stack num1;
    Stack num2;
    Stack result;
	
	Initialize(&num1);
    Initialize(&num2);
    Initialize(&result);
	
	test = fopen("test.txt","r");
    
    fscanf (test, "%s", string1);
    for (i = 0; i < strlen(string1); i ++)
    {
        temp = string1[i] - '0';
        Push(temp, &num1);
    }
    
    fscanf (test, "%s", string2);
    for (i = 0; i < strlen(string2); i ++)
    {
        temp = string2[i] - '0';
        Push(temp, &num2);
    }
    
    add (num1, num2, &result);
    print (&result);
    
	fclose(test);

	Destroy(&result);

	return EXIT_SUCCESS;
}

/*
 add(Big Num1, Big Num2, Result) : Result
 
 Function: gets the first item of num1 and num2, adds them together. If the sum greater than 10, then the difference between the sum and 10 is pushed to the top and the remainder is true (adds 1 to the next num). If the sum is less than 10, the sum is pushed. If num1 and num2 have elements, they are removed from the top of the stack.
 */
void add (Stack num1, Stack num2, Stack * result)
{
    int i = 0;
    int temp = 0;
    int n1 = 0;
    int n2 = 0;
    int bol = 0;
    int size1 = 0;
    int size2 = 0;
    
    size1 = num1.size;
    size2 = num2.size;
    i = 0;
    temp = 0;
    while (i < size1)
    {
        n1 = num1.first->item;
        if (i < size2-1) {n2 = num2.first->item;}
        else {n2 = 0;}
        temp = n1 + n2;
        
        if (bol == 1)
        {
            temp = temp + 1;
            bol = 0;
        }
        
        if (temp >= 10)
        {
            Push(temp - 10, result);
            bol = 1;
        }
        else
        {
            Push(temp, result);
        }
        if (i < size1) {Pop(&num1);}
        if (i < size2) {Pop(&num2);}
        i ++;
    }
}

/*
 print(Stack)
 
 Function: Prints the stack from top to bottom, leaving a space every 3 numbers.
 */
void print (Stack * S)
{
    StackNode * temp = S->first;
    int i = 0;
    
    while (S->size > i)
    {
        printf ("%d", temp->item);
        temp = temp->next;
        if (i%3 == 0)
        {
            printf (" ");
        }
        i ++;
    }
    printf("\n");
}

