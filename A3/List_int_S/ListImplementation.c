/*********************************************************************
 * FILE NAME: ListImplementation.c
 * PURPOSE: Sequential implementation of the Student List ADT.
 * AUTHOR: P. Matsakis (CIS2520, Assignment 1)
 * DATE: 21/09/2015
 * NOTES: . Some functions are static (they are auxiliary functions
 *          with local scope; they are not visible outside the file).
 *        . Only these static functions will need to be modified
 *          if the type of the list items (here, Student) changes. 
 *        . Only the other functions will need to be modified if
 *          the implementation of the List ADT changes.
 *        . As we will see, there is a better way to check whether
 *          the preconditions and postconditions are met.
 *********************************************************************/

#include "ListInterface.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void BubbleSort1 (List * L)
{
    int i, j, k;
    
    for (j = 1; j <= Size(L)-1; j ++)
    {
        for (i = 1; i <= Size(L) - j; i ++)
        {
            if (L->item[i-1] > L->item[i])
            {
                k = L->item[i];
                L->item[i] = L->item[i-1];
                L->item[i-1] = k;
            }
        }
    }
}

void BubbleSort2 (List * L)
{
    int swapped = 1;
    int i = 0;
    int j = 0;
    int k = Size(L);
    
    while (swapped == 1)
    {
        swapped = 0;
        for (i = 1; i <= k-1; i ++)
        {
            if (L->item[i-1] > L->item[i])
            {
                j = L->item[i];
                L->item[i] = L->item[i-1];
                L->item[i-1] = j;
                swapped = 1;
            }
        }
        k --;
    }
}
    
void MergeSort (List * L, int first, int last)
{
    int middle = 0;
    if (first < last)
    {
        middle = (first+last)/2;
        MergeSort(L, first, middle);
        MergeSort(L, middle+1, last);
        Merge(L, first, middle, last);
    }
}

void Merge (List * L, int first, int middle, int last)
{
    int i, j, k;
    
    int n1 = middle - first + 1;
    int n2 =  last - middle;
    
    int l[middle - first+1], R[last - middle];
    
    for (i = 0; i <= middle-first; i++)
    {
        l[i] = L->item[first+i];
    }
    
    for (j = 0; j <= last-middle-1; j++)
    {
        R[j] = L->item[middle+j+1];
    }
    
    i = j = 0;
    
    for (k = first; k <= last; k ++)
    {
        if (l[i] <= R[j])
        {
            L->item[k] = l[i];
            i++;
        }
        else
        {
            L->item[k] = R[j];
            j++;
        }
    }

    while (i < n1)
    {
        L->item[k] = l[i];
        i++;
        k++;
    }
    
    while (j < n2)
    {
        L->item[k] = R[j];
        j++;
        k++;
    }
}

void Initialize (List *L)
{
	L->size=0;
}


void Insert (int X, List *L)
{
  	int i = 0;
    for (i = L->size - 1; i > - 1; i --)
    {
        L->item[i+1] = L->item[i];
    }
    L->item[0] = X;
    L->size++;
}


void Remove (List *L)
{
	int i = 0;

	
    for (i = 0; i < L->size; i ++)
    {
        L->item[i] = L->item[i+1];
    }
    L->size--;
}


int Full (List *L)
{
	return L->size==100;
}


int Empty (List *L)
{
	return L->size==0;
}


int Size (List *L)
{
	return L->size;
}


void Peek (List *L, int *X)
{
    X = &L->item[0];
}


void Destroy (List *L)
{
	/*int i;
	for(i=0;i<L->size;i++)
		destroyItem(&L->item[i]);*/
}

