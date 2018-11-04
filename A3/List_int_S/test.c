/*********************************************************************
 * FILE NAME: myProgram.c
 * PURPOSE: Test program for sorting List implementations.
 * AUTHOR: Nick Major (CIS2520, Assignment 3)
 * DATE: 11/12/2015
 * NOTES: This program uses test data recorded in a text file
 *        (see test.txt). 
 *********************************************************************/


#include "ListInterface.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
			   
void print (List L)
{
    int i = 0;
    
    for (i = 0; i < Size(&L); i ++)
    {
        printf("%d ", L.item[i]);
    }
}

void bubble1 (List L)
{
    float sec;
    clock_t t1, t2;
    t1 = clock();
    BubbleSort1(&L);
    t2=clock();
    sec=(t2-t1)/(float)CLOCKS_PER_SEC;
    print(L);
    printf("BubbleSort1 in %.8f sec\n", sec);
}

void bubble2 (List L)
{
    float sec;
    clock_t t1, t2;
    t1 = clock();
    BubbleSort2(&L);
    t2=clock();
    sec=(t2-t1)/(float)CLOCKS_PER_SEC;
    print(L);
    printf("BubbleSort2 in %.8f sec\n", sec);
}

void merge (List L)
{
    float sec;
    clock_t t1, t2;
    t1 = clock();
    MergeSort(&L, 0, Size(&L)-1);
    t2=clock();
    sec=(t2-t1)/(float)CLOCKS_PER_SEC;
    print(L);
    printf("MergeSort in %.8f sec\n", sec);
}

int main(void)
{
	FILE *test;
    int temp;
    char string1[100];
    int i = 0;

	List L; 
	
	Initialize(&L);
	
	test=fopen("test.txt","r");
    fscanf (test, "%s", string1);
    for (i = 0; i < strlen(string1); i ++)
    {
        temp = string1[i] - '0';
        Insert(temp, &L);
    }
    
    print(L);
    printf("to sort\n");
    
    bubble1(L);
    bubble2(L);
    merge(L);
	
	fclose(test);
	Destroy(&L);
	return EXIT_SUCCESS;
}
