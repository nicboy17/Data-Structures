#include "StudentInterface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 InitializeStudent(Name, Grade, Student): Student
 
 Preconditions: An unitialized S is available. The elements exist and are of the correct type.
 PostConditions: The Student memory name is allocated, the grade and name is copied to the struct.
 */
void InitializeStudent (char *name, int grade, Student * S)
{
    S->name = (char*)malloc(strlen(name)+1);
    S->grade = grade;
    strcpy(S->name, name);
}

/*
 NameOfStudent(Student): Name
 
 Preconditions: Student exists and is not empty.
 PostConditions: Returns the name in the struct.
 */
char * NameOfStudent (Student S)
{
	return S.name;
}

/*
 GradeOfStudent(Student): Grade
 
 Preconditions: Student exists and is not empty.
 PostConditions: Returns the grade in the struct.
 */
int GradeOfStudent (Student S)
{
    return S.grade;
}

/*
 FreeStudent(Student): Student
 
 Preconditions: Student exists and is not empty.
 PostConditions: The memory allocated is freed.
 */
void FreeStudent (Student * S)
{
    S->grade = 0;
    strcpy(S->name, " ");
    free(S->name);
}
