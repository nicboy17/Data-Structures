/*********************************************************************
 * FILE NAME: QueueImplementation.c
 * PURPOSE: Sequential implementation of the Student queue ADT.
 * AUTHOR: Nick Major (CIS2520, Assignment 3)
 * DATE: 11/12/2015
 *********************************************************************/

#include "QueueInterface.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define DEBUG

static void copyItem (Item *Y, Item X)
{
	InitializeStudent(NameOfStudent(X),GradeOfStudent(X),Y);
}


static void destroyItem (Item *X)
{
	FreeStudent(X);
}

void Initialize (Queue * Q)
{
	Q->size = 0;
    Q->head = 0;
#ifdef DEBUG
	if(!Empty(Q) || Full(Q) || Size(Q)!=0) {
		printf("Violated postcondition for Initialize!\n");
		exit(EXIT_FAILURE);
	}
#endif
}


void Enqueue (Item I, Queue * Q) {
#ifdef DEBUG
  	Item Y;
	int oldSize=Size(Q);
	if(Full(Q)) {
		printf("Violated precondition for Enqueue!\n");
		exit(EXIT_FAILURE);
	}
#endif
    
    copyItem(&Q->items[(Q->size+Q->head)%6],I);
    Q->size ++;
    
#ifdef DEBUG
	Head(Q,&Y);
	if(Empty(Q) || Size(Q)!=oldSize+1) {
		printf("Violated postcondition for Enqueue!\n");
		exit(EXIT_FAILURE);
	}
#endif
}


void Dequeue (Queue * Q) {
#ifdef DEBUG
	if(Empty(Q)) {
		printf("Violated precondition for Dequeue!\n");
		exit(EXIT_FAILURE);
	}
#endif
    
    destroyItem(&Q->items[Q->head]);
    Q->head ++;
    Q->head %=6;
    Q->size --;

    
#ifdef DEBUG
	if(Full(Q)) {
		printf("Violated postcondition for Dequeue!\n");
		exit(EXIT_FAILURE);
	}
#endif
}

int Full (Queue * Q) {
	return Q->size==MAXLISTSIZE;
}


int Empty (Queue * Q) {
	return Q->size==0;
}


int Size (Queue * Q) {
	return Q->size;
}


void Head (Queue * Q, Item * I)
{
#ifdef DEBUG
	if(Empty(Q)) {
		printf("Violated precondition for Peek!\n");
		exit(EXIT_FAILURE);
	}
#endif
    copyItem(I,Q->items[(Q->size+Q->head)%6]);
}

void Tail (Queue * Q, Item * I)
{
#ifdef DEBUG
    if(Empty(Q)) {
        printf("Violated precondition for Peek!\n");
        exit(EXIT_FAILURE);
    }
#endif
    copyItem(I,Q->items[Size(Q)]);
}


void Destroy (Queue * Q)
{
	int i;
	for(i=0;i<Q->size;i++)
		destroyItem(&Q->items[i]);
}

