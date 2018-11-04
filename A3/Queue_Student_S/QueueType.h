#include "StudentInterface.h"
typedef Student Item;

#define MAXLISTSIZE 10
typedef struct {
	Item items[MAXLISTSIZE];
	int size;
    int head;
} Queue;
