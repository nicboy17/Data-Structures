#include "ListInterface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Status (List *L);
void PrintList (List * L);

int main (void)
{
    FILE * input;
    Student S;
    List L;
    char name[20];
    int grade = 0;
    int position = 0;
    char command[20];
    char buffer[50];
    
    Initialize(&L);
    
    input = fopen ("test.txt", "r");
    
    Status(&L);
    while (fgets (buffer, sizeof buffer, input) != NULL)
    {
        if (buffer[0] == 'I')
        {
            sscanf(buffer, "%s %d %s %d", command, &position, name, &grade);
            InitializeStudent (name, grade, &S);
            Insert (S, position, &L);
        }
        else if (buffer[0] == 'R')
        {
            sscanf(buffer, "%s %d", command, &position);
            Remove (position, &L);
        }
        
        Status(&L);
        PrintList (&L);
   }
    
    fclose(input);
    
    return EXIT_SUCCESS;
}

/*
 Status(List)
 
 Function: Prints the status of the List, if its empty and its size.
 */
void Status (List *L)
{
    int E = 0;
    
    E = Empty (L);
    
    if (E == 1)
    {
        printf ("List is empty; list is size of %d:\n", L->size);
    }
    else
    {
        printf ("List is not empty;list is size of %d:\n", L->size);
    }
}

/*
 PrintList(L)
 
Function: Prints the List from position 0 to the last position of the list. Prints: 'name' 'grade' newline ...
 */
void PrintList (List * L)
{
    int counter = 0;
    ListNode * temp = L->first;
    
    while (counter < L->size)
    {
        printf ("%s %d%% \n", temp->items.name, temp->items.grade);
        temp = temp->next;
        counter ++;
    }
}




