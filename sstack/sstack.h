#ifndef SSTACK
#define SSTACK

#define SIZE 10
#include <stdlib.h>

typedef int element;
typedef struct Stack
{
    element st[SIZE];
    int top;
}
Stack;

void sCreate(Stack* s);
int sIsFull(Stack s);
int sIsEmpty(Stack s);
void sPush(Stack* s, element e);
element sPop(Stack* s);
void sDelete(Stack* s);
void sCopyStack(Stack* s, Stack* c);

#include "sstack.c"
#endif
