/*********************************************************************
 * FILE NAME: myProgram.c
 * PURPOSE: Test program for Student queue implementations.
 * AUTHOR: Nick Major (CIS2520, Assignment 3)
 * DATE: 11/12/2015
 * NOTES: This program uses test data recorded in a text file
 *        (see test.txt). 
 *********************************************************************/

#include "QueueInterface.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static void showListSize (Queue *Q) {
	if(Empty(Q)) printf("List is empty; ");
	else printf("List is not empty; ");
	if(Full(Q)) printf("list is full; ");
	else printf("list is not full; ");
	printf("list is of size %d:\n",Size(Q));
}

static void showListContent (Queue *Q)
{
	int i;
	Student S;
	for(i = Q->head; i < Size(Q) + Q->head; i ++)
    {
		printf("\t%s %d%%\n",NameOfStudent(Q->items[i]),GradeOfStudent(Q->items[i]));
		FreeStudent(&S);
	}
}

int main(void)
{
	FILE *test;
	char s[20];
    int position, grade;
	
	Student S;
	Queue Q;
	
	Initialize(&Q);
	showListSize(&Q);
	showListContent(&Q);
	
	test=fopen("test.txt","r");
	while(fscanf(test,"%s %d",s,&position)>0)
    {
		if(strcmp(s,"Enqueue")==0)
        {
			fscanf(test,"%s %d",s,&grade);
			InitializeStudent(s,grade,&S);
			Enqueue(S,&Q);
			FreeStudent(&S);
		}
		if(strcmp(s,"Dequeue")==0)
        {
			Dequeue(&Q);
        }
		showListSize(&Q);
		showListContent(&Q);
	}
	
	fclose(test);
	Destroy(&Q);
	return EXIT_SUCCESS;
}

