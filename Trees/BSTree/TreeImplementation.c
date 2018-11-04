/*********************************************************************
 * FILE NAME: HeapImplemenation.c
 * PURPOSE: Implementation of a generic Binary Heap ADT
 * AUTHOR: Nick Major (CIS2520, Assignment 4)
 * DATE: 11/26/2015
 *********************************************************************/
#include "TreeType.h"
#include <stdlib.h>

int maxDepth (TreeNode * node)
{
    if (node == NULL)
    {
        return -1;
    }
    else
    {
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
        
        if (lDepth > rDepth)
        {
            return(lDepth+1);
        }
        else
        {
            return(rDepth+1);
        }
    }
}

int balance (TreeNode * node)
{
    if(node == NULL)
    {
        return 1;
    }
    else if(balance(node->left) && balance(node->right) && abs(maxDepth(node->left) - maxDepth(node->right)) <= 1)
    {
        return 1;
    }
    return 0;
}

extern TreeNode * min (TreeNode * node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

extern void destroy (TreeNode * toDie, Tree * T)
{
    if (toDie != NULL)
    {
        destroy(toDie->left, T);
        T->destroyValue(toDie->value);
        destroy(toDie->right, T);
        free (toDie);
    }
}

TreeNode * insert(TreeNode * root, Tree * T, void * value)
{
    TreeNode * node = NULL;
    
    if (root == NULL)
    {
        node = malloc(sizeof(TreeNode));
        node->value = T->copyValue(NULL, value);
        node->right = NULL;
        node->left = NULL;
        return node;
    }
    else
    {
        if (T->compareValues (value, root->value) < 0)
        {
            root->left = insert(root->left, T, value);
            
        }
        else if (T->compareValues (value, root->value) > 0)
        {
            root->right = insert(root->right, T, value);
        }
    }
    return root;
}

/*********************************************************************
 * FUNCTION NAME: Initialize
 * PURPOSE: Sets a Tree variable to the empty Binary Search Tree.
 * ARGUMENTS: . The address of the Tree variable to be initialized
 *              (Tree *)
 *            . A pointer to a copy function
 *              ----------------------------
 *              PURPOSE: Makes a copy of a value.
 *              ARGUMENTS: . NULL, or the address (void *) of
 *                           the location in memory where the
 *                           copy must be stored
 *                         . The address (void *) of the value
 *                           to be copied
 *              RETURNS: The address (void *) of the location in
 *                       memory where the copy has been stored
 *              NOTES: If the first argument is NULL, the copy
 *                     function allocates memory for the copy,
 *                     and this memory should later be freed
 *                     by the destroy function below.
 *              -------------------------------
 *            . A pointer to a destroy function
 *              -------------------------------
 *              PURPOSE: Frees memory that may have been
 *                       allocated by the copy function above.
 *              ARGUMENT: The address of the value to be destroyed
 *                        (void *); this address must have been
 *                        returned by the copy function called
 *                        with NULL as its first argument
 *              -------------------------------
 *            . A pointer to a compare function
 *              -------------------------------
 *              PURPOSE: Compares two values.
 *              ARGUMENTS: . A pointer to a first value (void *)
 *                         . A pointer to a second value (void *)
 *              RETURNS: The integer
 *                       -1 if the 1st value is less than the 2nd value,
 *                        0 if the two values are equal,
 *                        1 otherwise
 *              -----------------------
 * NOTES: Initialize is the only function that may be used right
 *        after the declaration of the Tree variable or a call
 *        to Destroy, and it should not be used otherwise.
 *********************************************************************/
extern void Initialize (Tree * T, void * (*copyValue) (void*, void*), void (*destroyValue)(void*), int (*compareValues)(void*, void*))
{
    T->root = NULL;
    T->size = 0;
    T->copyValue = copyValue;
    T->destroyValue = destroyValue;
    T->compareValues = compareValues;
}

/*********************************************************************
 * FUNCTION NAME: Insert
 * PURPOSE: Inserts a value in a Binary Search Tree.
 * ARGUMENTS: . The address of the Tree (Tree *)
 *            . The address of the value to be inserted (void *)
 *********************************************************************/
extern void Insert (Tree * T, void * I)
{
    T->root = insert (T->root, T, I);
    T->size ++;
}

/*********************************************************************
 * FUNCTION NAME: Minimum
 * PURPOSE: Finds the least value (according to the compare
 *          function whose address was passed to Initialize)
 *          of a Binary Search Tree.
 * ARGUMENTS: . The address of the Tree (Tree *)
 *            . The address (void *) where a copy
 *              of the least value should be stored
 * RETURNS: 1 if the minimum has been found,
 *          i.e., if the Tree is not empty,
 *          0 otherwise
 *********************************************************************/
extern int Minimum (Tree *T, void *I)
{
    TreeNode * node = NULL;
    if (T->root == NULL)
    {
        return 0;
    }
    node = min(T->root);
    T->current = node;
    T->copyValue(I, node->value);
    return 1;
}

/*********************************************************************
 * FUNCTION NAME: Successor
 * PURPOSE: Finds the successor (according to the compare
 *          function whose address was passed to Initialize)
 *          in a Binary Search Tree of the last value found by
 *          Successor or Minimum (whichever was called last).
 * ARGUMENTS: . The address of the Tree (Tree *)
 *            . The address (void *) where a copy
 *              of the successor should be stored
 * RETURNS: 1 if the successor has been found,
 *          i.e., if the Tree is not empty and if the
 *          last value found by Minimum or Successor
 *          was not the greatest value in the Tree,
 *          0 otherwise
 * NOTES: A call to Successor must be immediately
 *        preceded by a call to Successor or Minimum.
 *********************************************************************/
extern int Successor (Tree *T, void *I)
{
    TreeNode * parent = NULL;
    TreeNode * node = NULL;
    
    if(T->root == NULL)
    {
        return 0;
    }
    
    if(T->current->right != NULL)
    {
        node = T->current->right;
        parent = min(node);
        T->current = parent;
        T->copyValue(I, parent->value);
        return 1;
    }
    
    if(T->current->right != NULL)
    {
        T->current = min(T->current->right);
        T->copyValue(I, T->current->right->value);
        return 1;
    }
    
    node = T->current;
    parent = T->current->parent;
    
    while(parent != NULL && node == parent->right)
    {
        node = parent;
        parent = parent->parent;
    }
    if(parent == NULL)
    {
        return 0;
    }
    T->current = parent;
    T->copyValue (I,parent->value);
    return 1;
}

/*********************************************************************
 * FUNCTION NAME: Size
 * PURPOSE: Finds the number of values stored in a Binary Search Tree.
 * ARGUMENT: The address of the Tree (Tree *)
 * RETURNS: The number of values stored in the Tree
 *********************************************************************/
extern int Size (Tree * T)
{
    return T->size;
}

/*********************************************************************
 * FUNCTION NAME: Height
 * PURPOSE: Calculates the height of a Binary Search Tree.
 * ARGUMENT: The address of the Tree (Tree *)
 * RETURNS: The height of the Tree
 * NOTES: The height of the empty Tree is -1.
 *********************************************************************/
extern int Height (Tree *T)
{
    return maxDepth(T->root);
}

/*********************************************************************
 * FUNCTION NAME: Balanced
 * PURPOSE: Checks whether a Binary Search Tree is balanced.
 * ARGUMENT: The address of the Tree (Tree *)
 * RETURNS: 1 if the Tree is balanced, 0 otherwise
 * NOTES: A Tree is balanced if it is empty or if for any node N
 *        the heights of N's subTrees are equal or differ by 1.
 *********************************************************************/
extern int Balanced (Tree *T)
{
    if (balance(T->root) == 1)
    {
        return 1;
    }
    return 0;
}

/*********************************************************************
 * FUNCTION NAME: Destroy
 * PURPOSE: Frees memory that may have been
 *          allocated by Initialize and Insert.
 * ARGUMENTS: The address of the Tree to be destroyed (Tree *)
 * NOTES: The last function to be called should always be Destroy.
 *********************************************************************/
extern void Destroy (Tree *T)
{
    destroy(T->root, T);
}
