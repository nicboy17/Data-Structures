/*********************************************************************
 * FILE NAME: myProgram.c
 * PURPOSE: Test program for a generic Binary Search Tree implementation
 * AUTHOR: Nick Major (CIS2520, Assignment 4)
 * DATE: 11/26/2015
 *********************************************************************/

#include "StudentInterface.h"
#include "TreeInterface.h"
#include <stdio.h>
#include <stdlib.h>

/*from A1key*/
/*************************************************
 PURPOSE: Makes a copy of a value.
 ARGUMENTS: . NULL, or the address (void *) of
 *            the location in memory where the
 *            copy must be stored
 *          . The address (void *) of the value
 *            to be copied
 RETURNS: The address (void *) of the location in
 *        memory where the copy has been stored;
 *        NULL if no copy could be made
 **************************************************/
static void * copyStudent (void * X, void * Y)
{
    Student S1 = *(Student*)Y;
    
    if (X == NULL)
    {
        X = malloc(sizeof(Student));
    }
    if (X != NULL)
    {
        InitializeStudent(NameOfStudent(S1), GradeOfStudent(S1), X);
    }
    return X;
}

/*from A1key*/
/************************************************
 PURPOSE: Frees memory that may have been
 *        allocated by the copy function above.
 ARGUMENT: The address of the value to be destroyed
 *         (void *); this address must have been
 *         returned by the copy function called
 *         with NULL as its first argument
 ***************************************************/
static void destroyStudent (void * X)
{
    FreeStudent(X);
    free(X);
}

/*******************************************************************
 PURPOSE: Compares two values.
 ARGUMENTS: . A pointer to a first value (void *)
 *          . A pointer to a second value (void *)
 RETURNS: The integer -1 if the 1st value is less than the 2nd value,
 *                    0 if the two values are equal,
 *                    1 otherwise
 ******************************************************************/
static int compareStudents (void * X, void * Y)
{
    Student S1 = *(Student*)X;
    Student S2 = *(Student*)Y;
    
    if(GradeOfStudent(S1) > GradeOfStudent(S2))
    {
        return -1;
    }
    if(GradeOfStudent(S1) == GradeOfStudent(S2))
    {
        return 0;
    }
    return 1;
}

void printTree (TreeNode * node)
{
    Student * temp;
    if (node != NULL)
    {
        printTree(node->right);
        temp = (Student *)node->value;
        printf("%s\t%d%%\n", NameOfStudent(*temp), GradeOfStudent(*temp));
        printTree(node->left);
    }
}

int main (int argc, char* argv[])
{
    FILE * input;
    char name[20];
    int grade = 0;
    Student S;
    Tree T;
    
    Initialize(&T, copyStudent, destroyStudent, compareStudents);
    printf("Initialize()\nSize=%d, Height=%d, ", T.size, Height(&T));
    if(Balanced(&T) == 1){printf("Balanced=YES\n");}
    else{printf("Balanced=NO\n");};
    
    input=fopen("test.txt","r");
    while(fscanf(input,"%s %d", name, &grade)==2)
    {
        InitializeStudent(name, grade, &S);
        Insert(&T, &S);
        printf("\nInsert(%s,%d)\nSize=%d, Height=%d, ", name, grade, T.size, Height(&T));
        if(Balanced(&T) == 1){printf("Balanced=YES\n");}
        else{printf("Balanced=NO\n");};
        FreeStudent(&S);
    }
    fclose(input);
    
    printf ("\n");
    
    printTree(T.root);
    
    Destroy(&T);
    return EXIT_SUCCESS;
}
