/*********************************************************************
 * FILE NAME: ListImplementation.c
 * PURPOSE: One-way linked implementation of the Student List ADT.
 * AUTHOR: Nick Major (CIS2520, Assignment 3)
 * DATE: 11/12/2015
 *********************************************************************/


#include "ListInterface.h"
#include <stdlib.h>
#include <stdio.h>


/********************************************************************* 
 * FUNCTION NAME: Reverse
 * PURPOSE: Reverses a List
 * (the first Item becomes the last and vice versa).
 * ARGUMENTS: The address of the List to be reversed (List *L)
 *********************************************************************/
extern void Reverse (List * L)
{
    List rest;
    Initialize(&rest);

    if (L->first == NULL)
    {
        L = NULL;
    }
    else if (L->first->next == NULL)
    {
        return;
    }
    else
    {
        rest.first = L->first->next;
        Reverse(&rest);
        L->first->next->next = L->first;
        L->first->next = NULL;
        L->first = rest.first;
    }
}

static void copyItem (Item *Y, Item X) {
	InitializeStudent(NameOfStudent(X),GradeOfStudent(X),Y);
}


static void destroyItem (Item *X) {
	FreeStudent(X);
}


static ListNode *moveTo (int position, List *L) {
	int i;
	ListNode *p=L->first;
	for(i=0;i<position;i++) p=p->next;
	return p;
}


void Initialize (List *L) {
	L->size=0;
	L->first=NULL;
}


void Insert (Item X, int position, List *L) {
	ListNode *p, *q;
	
	L->size++;
	q=(ListNode *)malloc(sizeof(ListNode));
	copyItem(&q->item,X);
			 
	if(position==0) {
		q->next=L->first;
		L->first=q;
	}
	else {
		p=moveTo(position-1,L);
		q->next=p->next;
		p->next=q;
	}
}


void Remove (int position, List *L) {
	ListNode *p, *q;
	
	if(position==0) {
		q=L->first;
		L->first=q->next;
	}
	else {
		p=moveTo(position-1,L);
		q=p->next;
		p->next=q->next;
	}
	
	destroyItem(&q->item);
	free(q);
	L->size--;
}


int Full (List *L) {
	return 0;
}


int Empty (List *L) {
	return L->size==0;
}


int Size (List *L) {
	return L->size;
}


void Peek (int position, List *L, Item *X) {
	ListNode *p;
	p=moveTo(position,L);
	copyItem(X,p->item);
}


void Destroy (List *L) {
	int i;
	ListNode *p, *q;
	
	p=L->first;
	for(i=0;i<L->size;i++) {
		q=p;
		p=p->next;
		destroyItem(&q->item);
		free(q);
	}
}

