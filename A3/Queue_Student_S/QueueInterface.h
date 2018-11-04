 /*********************************************************************
 * FILE NAME: ListInterface.h
 * PURPOSE: Interface of the Student Queue ADT
 * AUTHOR: Nick Major (CIS2520, Assignment 3)
 * DATE: 11/12/2015
 *********************************************************************/
#include "QueueType.h"

/*********************************************************************
 * FUNCTION NAME: Initialize
 * PURPOSE: Sets a List variable to the empty Queue.
 * ARGUMENTS: The address of the Queue variable to be initialized
 *            (Queue *)
 * ENSURES (postconditions): 
 *          . Empty will return true (a nonzero integer).
 *          . Size will return 0.
 * NOTES: Initialize is the only function that may be used right
 *        after the declaration of the Queue variable or a call
 *        to Destroy, and it should not be used otherwise.
 *********************************************************************/
extern void Initialize (Queue * Q);

/*********************************************************************
 * FUNCTION NAME: Insert
 * PURPOSE: Inserts an Item to the back of the Queue.
 * ARGUMENTS: . The Item to be inserted (Item)
 *            . The address of the Queue (Queue *L)
 * REQUIRES (preconditions):
 *          . The Queue should not be full.
 * ENSURES: . Empty will return false (0).
 *          . Size will return the first integer greater
 *            than the size of the Queue before the call.
 *          . Peek will return the item at the head of
 *            the Queue.
 *********************************************************************/
extern void Enqueue (Item I, Queue * Q);

/*********************************************************************
 * FUNCTION NAME: Remove
 * PURPOSE: Removes an Item from the front of the Queue.
 * ARGUMENTS:
 *          . The address of the Queue (Queue *L)
 * REQUIRES:
 *          . The Queue should not be empty.
 * ENSURES: . Full will return false (0).
 *          . Size will return the first integer lower
 *            than the size of the Queue before the call.
 *********************************************************************/
extern void Dequeue (Queue * Q);

/*********************************************************************
 * FUNCTION NAME: Full
 * PURPOSE: Determines whether a Queue is full.
 * ARGUMENTS: The address of the Queue (Queue *)
 * RETURNS: True (a nonzero integer) if the Queue is full,
 *          false (0) otherwise
 *********************************************************************/
extern int Full (Queue * Q);

/*********************************************************************
 * FUNCTION NAME: Empty
 * PURPOSE: Determines whether a Queue is empty.
 * ARGUMENTS: The address of the Queue (Queue *)
 * RETURNS: True (a nonzero integer) if the Queue is empty,
 *          false (0) otherwise
 *********************************************************************/
extern int Empty (Queue * Q);

/*********************************************************************
 * FUNCTION NAME: Size
 * PURPOSE: Finds the size of a Queue.
 * ARGUMENTS: The address of the Queue (Queue *)
 * RETURNS: The size of the Queue (int)
 *********************************************************************/
extern int Size (Queue * Q);

/*********************************************************************
 * FUNCTION NAME: Head
 * PURPOSE: Returns the head of the Queue.
 * ARGUMENTS:
 *            . The address of the Queue (Queue *L)
 *            . The address of the Item
 *              the Item found should be copied to
 * REQUIRES:
 *           . The Queue should not be empty.
 *********************************************************************/
extern void Head (Queue * Q, Item * I);

/*********************************************************************
 * FUNCTION NAME: Tail
 * PURPOSE: Returns the last element in the Queue.
 * ARGUMENTS:
 *            . The address of the List (List *L)
 *            . The address of the Item
 *              the Item found should be copied to
 * REQUIRES:
 *           . The Queue should not be empty.
 *********************************************************************/
extern void Tail (Queue * Q, Item * I);

/*********************************************************************
 * FUNCTION NAME: Destroy
 * PURPOSE: Frees memory that may have been allocated
 *          by Initialize, Insert or Remove.
 * ARGUMENTS: The address of the Queue to be destroyed (Queue *) 
 * NOTES: The last function to be called should always be Destroy. 
 *********************************************************************/
extern void Destroy (Queue * Q);


