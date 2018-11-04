#include "ListInterface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 Initialize(List): List
 
 Preconditions: An unitialized list is available. The element as the parameter is of the correct type for the list.
 PostConditions: The size is set to 0, the List is added to memory, the first element is added to memory, and
    the second element is set to NULL;
 */
void Initialize (List * L)
{
    L->size = 0;
    L = malloc(sizeof(List));
    L->first = malloc(sizeof(ListNode));
    L->first->next = NULL;
}

/*
 Insert(Student, Position, List): List
 
 Preconditions: An initialized list is available. The element as the parameter is of the correct type for the list. 
    The Item exists and the position is greater than 0 and less than the list size.
 PostConditions: The element is added to the specified Position in the list, and the length of the list is increased by one. Before the Position is pointed at the new element and the new element is pointed at everything after
    the Position.
 */
void Insert (Item X, int position, List * L)
{
    ListNode * temp = malloc(sizeof (ListNode));
    int i = 0;
    ListNode * it = NULL;

    temp->items.name = X.name;
    temp->items.grade = X.grade;
    temp->next = NULL;
    
    it = L->first;
    L->size ++;
    
    if (position == 0)
    {
        temp->next = L->first;
        L->first = temp;
    }
    else if (position > 0 && position <= L->size)
    {
        for (i = 1; i < position; i ++)
        {
            it = it->next;
        }
        temp->next = it->next;
        it->next = temp;
    }
}

/*
 Remove(Position, List): List
 
 Preconditions: An initialized list is available. The element as the parameter is of the correct type for the list.
    The Position is greater than 0 and less than the size of the list.
 PostConditions: The element is removed from the specified Position, the length of the list is decreased by one. The List adjusts by pointing to the element after the specified Position.
 */
void Remove (int position, List * L)
{
    ListNode * it = NULL;
    it = L->first;
    int i = 0;
    
    if (position == 0)
    {
        L->first = L->first->next;
    }
    else if (position > 0 && position <= L->size)
    {
        for (i = 1; i < position; i ++)
        {
            it = it->next;
        }
        it = it->next->next;
    }
    
    L->size --;
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
    int i = 0;
    ListNode * temp = L->first;
    
    if (position < L->size && position > 0)
    {
        for (i = 0; i < position; i ++)
        {
            X = &temp->items;
            temp = temp->next;
        }
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
