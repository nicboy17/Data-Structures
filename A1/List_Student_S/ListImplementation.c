#include "ListInterface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 Initialize(List): List
 
 Preconditions: An initialized list is available. The element as the parameter is of the correct type for the list.
 PostConditions: The size is set to 0, the List is added to memory.
 */
void Initialize (List * L)
{
    L->size = 0;
    L = malloc(sizeof(List));
}

/*
 Insert(Student, Position, List): List
 
 Preconditions: An initialized list is available. The element as the parameter is of the correct type for the list.
 The Item exists and the position is greater than 0 and less than the list size.
 PostConditions: The element is added to the specified Position in the list, and the length of the list is increased by one. The element is added to the specified position and the rest of the array is shifted down 1.
 the Position.
 */
void Insert (Item X, int position, List * L)
{
    int i = 0;
    
    if (L->size == 0 && position <= MAXLISTSIZE && position >= 0)
    {
        L->items[position].grade = X.grade;
        strcpy(L->items[position].name, X.name);
    }
    else
    {
        for (i = L->size - 1; i > position - 1; i --)
        {
            L->items[i+1].grade = L->items[i].grade;
            strcpy(L->items[i+1].name, L->items[i].name);
        }
        L->items[position].grade = X.grade;
        strcpy(L->items[position].name, X.name);
    }

    L->size ++;
}

/*
 Remove(Position, List): List
 
 Preconditions: An initialized list is available. The element as the parameter is of the correct type for the list.
 The Position is greater than 0 and less than the size of the list.
 PostConditions: The element is removed from the specified Position, the length of the list is decreased by one. The array is shifted back 1;
 */
void Remove (int position, List * L)
{
    int i = 0;
    
    if (L->size == 1 && position <= MAXLISTSIZE && position >= 0)
    {
        FreeStudent(&L->items[position]);
    }
    else
    {
        FreeStudent(&L->items[position]);
        for (i = position; i < L->size; i ++)
        {
            L->items[i].grade = L->items[i+1].grade;
            strcpy(L->items[i].name, L->items[i+1].name);
        }
    }
    L->size --;
}

/*
 Empty(List): List
 
 Preconditions: An initialized list is available. The element as the parameter is of the correct type for the list.
 PostConditions: If the List is empty, 1 is returned. If the List is not empty, 0 is returned.
 */
int Full (List * L)
{
    int temp = 0;
    
    if (L->size == MAXLISTSIZE)
    {
        temp = 1;
    }
    else
    {
        temp = 0;
    }
    
	return temp;
}

/*
 Empty(List): List
 
 Preconditions: An initialized list is available. The element as the parameter is of the correct type for the list.
 PostConditions: If the List is empty, 1 is returned. If the List is not empty, 0 is returned.
 */
int Empty (List * L)
{
    int temp = 0;
    
    if (L->size == 0)
    {
        temp = 1;
    }
    else
    {
        temp = 0;
    }
    
    return temp;
}

/*
 Size(List): List
 
 Preconditions: An initialized list is available. The element as the parameter is of the correct type for the list.
 PostConditions: The size of the List from structure is returned.
 */
int Size (List * L)
{
    return L->size;
}

/*
 Peek(Position, List, Item): List
 
 Preconditions: An initialized list is available. The element as the parameter is of the correct type for the list.
 Item exits and the position is greater than 0 and less than the size of the list.
 PostConditions: The List is cycled to its specified position and copied to Item.
 */
void Peek (int position, List * L, Item * X)
{
    if (position < MAXLISTSIZE && position > 0)
    {
        X->grade = L->items[position].grade;
        strcpy(X->name, L->items[position].name);
    }
}

/*
 Destroy(List): List
 
 Preconditions: An initialized list is available. The element as the parameter is of the correct type for the list.
 PostConditions: The size of the list is set to zero and the memory allocated is freed.
 */
void Destroy (List * L)
{
    L->size = 0;
    free(L);
}
