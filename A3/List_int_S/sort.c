/*********************************************************************
 * FILE NAME: sort.c
 * PURPOSE: gives worst, average, and best case times for sorting functions.
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

//checks bubble 1 time
float bubble1 (List L)
{
    float sec;
    clock_t t1, t2;
    t1 = clock();
    BubbleSort1(&L);
    t2=clock();
    sec=(t2-t1)/(float)CLOCKS_PER_SEC;
    return sec;
}

//checks bubble 2 time
float bubble2 (List L)
{
    float sec;
    clock_t t1, t2;
    t1 = clock();
    BubbleSort2(&L);
    t2=clock();
    sec=(t2-t1)/(float)CLOCKS_PER_SEC;
    return sec;
}

//checks merge time
float merge (List L)
{
    float sec;
    clock_t t1, t2;
    t1 = clock();
    MergeSort(&L, 0, Size(&L));
    t2=clock();
    sec=(t2-t1)/(float)CLOCKS_PER_SEC;
    return sec;
}

//generates list decreasing (opposite of sorted)
void backwards (List * L, int size)
{
    int i = 0;
    for (i = 1; i <= size; i ++)
    {
        Insert(i, L);
    }
}

//generates list increasing (all ready sorted)
void forwards (List * L, int size)
{
    int i = 0;
    for (i = size; i > 0; i --)
    {
        Insert(i, L);
    }
}

//Generates random lists of some size
void Rand (List * L, int size)
{
    int i = 0;
    
    for (i = 0; i < size; i ++)
    {
        Insert(rand() % 500, L);
    }
}

int main(int argc, char *argv[])
{
    int number, size;
    int i = 0;
    float sec = 0.0;
    
    if (argv == NULL || argv[0] == NULL|| argv[1] == NULL)
    {
        printf("Sorry, please enter the number of lists and the size of the lists seperated by a space\n");
        exit(0);
    }
    else
    {
        number = atoi(argv[1]) + 3;
        size = atoi(argv[2])+1;
    }
    
    List L[size][number];
    
    Initialize(*L);
    
    forwards (L[0], size);
    backwards (L[1], size);
    
    for (i = 2; i < number; i ++)
    {
        Rand(L[i], size);
    }
    
    //Bubble Sort 1
    printf("BubbleSort1:\n");
    sec = bubble1(*L[0]);
    printf("%.8f\n", sec);
    
    sec = 0;
    for (i = 2; i < number; i ++)
    {
        sec = sec + bubble1(*L[i]);
    }
    sec = sec/(number-1);
    printf("%.8f\n", sec);
    
    sec = 0;
    sec = bubble1(*L[1]);
    printf("%.8f\n", sec);
    
    //Bubble Sort 2
    printf("BubbleSort2:\n");
    sec = bubble2(*L[0]);
    printf("%.8f\n", sec);
    
    sec = 0;
    for (i = 2; i < number; i ++)
    {
        sec = sec + bubble2(*L[i]);
    }
    sec = sec/(number-1);
    printf("%.8f\n", sec);
    
    sec = 0;
    sec = bubble2(*L[1]);
    printf("%.8f\n", sec);
    
    //Merge Sort
    printf("MergeSort:\n");
    sec = merge(*L[0]);
    printf("%.8f\n", sec);
    
    sec = 0;
    for (i = 2; i < number; i ++)
    {
        sec = sec + merge(*L[i]);
    }
    sec = sec/(number-1);
    printf("%.8f\n", sec);
    
    sec = 0;
    sec = merge(*L[1]);
    printf("%.8f\n", sec);
    
    
    Destroy(*L);
    return EXIT_SUCCESS;
}

