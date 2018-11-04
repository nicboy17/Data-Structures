/*********************************************************************
 * FILE NAME: ListImplementation.c
 * PURPOSE: One-way linked implementation of the Student List ADT.
 * AUTHOR: P. Matsakis (CIS2520, Assignment 1)
 * DATE: 21/09/2015
 * NOTES: . Some functions are static (they are auxiliary functions
 *          with local scope; they are not visible outside the file).
 *        . Only the first two functions will need to be modified
 *          if the type of the list items (here, Student) changes. 
 *        . Only the other functions will need to be modified if
 *          the implementation of the List ADT changes.
 *        . For preconditions and postconditions,
 *          see the sequential implementation (no changes).
 *********************************************************************/

#include "StackInterface.h"
#include <stdlib.h>
#include <assert.h>

/*
Initialize(Stack): Stack

Preconditions: An unitialized stack is available. The element as the parameter is of the correct type for the stack.
PostConditions: The size is set to 0 and the first element is is set to NULL;
*/
void Initialize (Stack * S)
{
	S->size = 0;
	S->first = NULL;
    
    assert (Empty(S) > 0);
    assert (Size(S) == 0);
}

/*
 Push (Item, Stack): Stack
 
 Preconditions: An initialized stack is available. The element as the parameter is of the correct type for the stack and exist.
 PostConditions: The element is added to the top of the list, and the length of the list is increased by one. The new StackNode is pointed at the new element and the the next element is pointed at the original stack.
 */
void Push (Item X, Stack * S)
{
    StackNode * q = NULL;
    
    assert (S != NULL);
    
    S->size ++;
    q = malloc(sizeof(StackNode));
    q->item = X;
    
    q->next = S->first;
    S->first = q;
    
    assert (Empty(S) == 0);
}

/*
 Remove(Stack): Stack
 
 Preconditions: An initialized stack is available. The element as the parameter is of the correct type for the list.
 PostConditions: The element is removed from the top of the stack, the length of the stack is decreased by one. The stack adjusts by pointing to the element after the top of the stack and then is removed from memory.
 */
void Pop (Stack * S)
{
    StackNode * q = NULL;
    
    assert (S != NULL);
	
    q = S->first;
    S->first = q->next;
    
	free(q);
	S->size--;
    
    assert (Full(S) == 0);
}

/*
 Full(Stack): Stack
 
 Preconditions: An initialized stack is available. The element as the parameter is of the correct type for the stack.
 PostConditions: The stack is never full so, 0 is returned.
 */
int Full (Stack * S)
{
	return 0;
}

/*
 Empty(Stack): Stack
 
 Preconditions: An initialized stack is available. The element as the parameter is of the correct type for the stack.
 PostConditions: If the stack is empty, 1 is returned. If the stack is not empty, 0 is returned.
 */
int Empty (Stack * S)
{
	return S->size==0;
}

/*
 Size(Stack): int
 
 Preconditions: An initialized stack is available. The element as the parameter is of the correct type for the stack.
 PostConditions: The size of the stack from structure is returned.
 */
int Size (Stack * S)
{
	return S->size;
}

/*
 Top(Stack, Item): Item
 
 Preconditions: An initialized stack is available. The element as the parameter is of the correct type for the stack.
 PostConditions: The stacks first item is copied to X and returned;
 */
void Top (Stack * S, Item * X)
{
    assert (S != NULL);
    assert (X != NULL);
    
    X = &S->first->item;
}

/*
 Destroy(Stack): Stack
 
 Preconditions: An initialized stack is available. The element as the parameter is of the correct type for the stack.
 PostConditions: The size of the stack is set to zero and the memory allocated is freed.
 */
void Destroy (Stack * S)
{
	int i = 0;
    S->size = 0;
	
	for (i = 0; i < S->size; i ++)
    {
		free(S->first);
        S->first = S->first->next;
	}
}

