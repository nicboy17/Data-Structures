#include "StudentInterface.h"
typedef Student Item;

typedef struct ListNode
{
	Item items;
    struct ListNode * next;
} ListNode;

typedef struct List
{
    int size;
    ListNode * first;
}List;
