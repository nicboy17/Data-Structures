#include "ListInterface.h"
#include <stdio.h>
#include <stdlib.h>

void Status (List L);
void PrintList (List L);

int main (void)
{
    FILE * input;
    Student S;
    List L;
    char name[20];
    int grade = 0;
    int position = 0;
    char buffer[50];
    
    Initialize(&L);
    
    input = fopen ("test.txt", "r");
    
    Status(L);
    while(fgets (buffer, sizeof buffer, input) != NULL)
    {
        if (buffer[0] == 'I')
        {
            sscanf(buffer, "Insert %d %s %d", &position, name, &grade);
            InitializeStudent (name, grade, &S);
            Insert (S, position, &L);
        }
        else if (buffer[0] == 'R')
        {
            sscanf(buffer, "Remove %d", &position);
            Remove (position, &L);
        }
        Status(L);
        PrintList(L);
    }
    
    fclose(input);
    
    return EXIT_SUCCESS;
}

/*
 Status(List)
 
 Function: Prints the status of the List, if its empty and its size.
 */
void Status (List L)
{
    int F = 0;
    int E = 0;
    
    F = Full (&L);
    E = Empty (&L);
    
    if (E == 1 && F == 0)
    {
        printf ("List is empty; list is not full; list is size of %d:\n", L.size);
    }
    else if (E == 0 && F == 1)
    {
        printf ("List is not empty; list is full; list is size of %d:\n", L.size);
    }
    else
    {
        printf ("List is not empty; list is not full; list is size of %d:\n", L.size);
    }
}

/*
 PrintList(L)
 
 Function: Prints the List from position 0 to the last position of the list. Prints: 'name' 'grade' newline ...
 */
void PrintList (List L)
{
    int i = 0;
    
    for (i = 0; i < L.size; i ++)
    {
        printf ("%s %d%% \n", NameOfStudent(L.items[i]), GradeOfStudent(L.items[i]));
    }
}
