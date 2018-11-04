/*********************************************************************
 * FILE NAME: ListType.h
 * PURPOSE: Concrete data structure definition of Student List.
 * AUTHOR: P. Matsakis (CIS2520, Assignment 1)
 * DATE: 21/09/2015
 *********************************************************************/

typedef int Item;

typedef struct StackNode
{
    Item item;
    struct StackNode *next;
} StackNode;

typedef struct Stack
{
	int size;
    StackNode *first;
} Stack;
