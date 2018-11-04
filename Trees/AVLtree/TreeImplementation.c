/*********************************************************************
 * FILE NAME: HeapImplemenation.c
 * PURPOSE: Implementation of a AVL Binary Search Tree ADT
 * AUTHOR: Nick Major (CIS2520, Assignment 4)
 * DATE: 11/26/2015
 *********************************************************************/
#include "TreeType.h"
#include <stdlib.h>

extern int maxDepth (TreeNode * node)
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

extern int balance (TreeNode * node)
{
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
}

/*new*/
TreeNode * rotateRight(TreeNode * oldRoot)
{
    TreeNode * temp = oldRoot->left;
    oldRoot->left = temp->right;
    temp->right = oldRoot;
    return temp;
}

/*new*/
TreeNode * rotateLeft(TreeNode * oldRoot)
{
    TreeNode * temp = oldRoot->right;
    oldRoot->right = temp->left;
    temp->left = oldRoot;
    return temp;
}

TreeNode * min (TreeNode * node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

void destroy (TreeNode * toDie, Tree * T)
{
    if (toDie != NULL)
    {
        destroy(toDie->left, T);
        T->destroyValue(toDie->value);
        destroy(toDie->right, T);
        free (toDie);
    }
}

/*modified*/
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
    
    if (balance(root) == -2)
    {
        if (maxDepth(root->left) - maxDepth(root->right) == 2)
        {
            if (maxDepth(root->left->right) > maxDepth(root->left->left))
            {
                root->left = rotateLeft(root->left);
            }
            return rotateRight(root);
        }
        else if (maxDepth(root->right) - maxDepth(root->left) == 2)
        {
            if (maxDepth(root->right->left) > maxDepth(root->right->right))
            {
                root->right = rotateRight(root->right);
            }
            return rotateLeft(root);
        }
    }
    
    return root;
}

extern void Initialize (Tree * T, void * (*copyValue) (void*, void*), void (*destroyValue)(void*), int (*compareValues)(void*, void*))
{
    T->root = NULL;
    T->size = 0;
    T->copyValue = copyValue;
    T->destroyValue = destroyValue;
    T->compareValues = compareValues;
}

extern void Insert (Tree * T, void * I)
{
    T->root = insert (T->root, T, I);
    T->size ++;
}

extern int Minimum (Tree * T, void * I)
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

extern int Successor (Tree * T, void * I)
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
    
    node = T->current;
    parent = node->parent;
    
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

extern int Size (Tree * T)
{
    return T->size;
}

extern int Height (Tree * T)
{
    return maxDepth(T->root);
}

extern int Balanced (Tree * T)
{
    if (balance(T->root) != -2)
    {
        return 1;
    }
    return 0;
}

extern void Destroy (Tree * T)
{
    destroy(T->root, T);
}
