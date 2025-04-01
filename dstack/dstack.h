#ifndef DSTACK
#define DSTACK

#include <stdlib.h>

typedef int element;

typedef struct Node
{
    element e;
    struct Node* next;
}
Node;

void dCreate(Node** s);
int dIsEmpty(Node* s);
void dPush(Node** s, element e);
element dPop(Node** s);
void dDelete(Node** s);
void dPrintStack(Node** s);

#include "dstack.h"

#endif
