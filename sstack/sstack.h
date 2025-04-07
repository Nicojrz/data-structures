#ifndef SSTACK
#define SSTACK

#define SIZE 10
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Stack
{
    element st[SIZE];
    int top;
}
Stack;

void create_stack(Stack* s);
int isFull_stack(Stack s);
int isEmpty_stack(Stack s);
void push_stack(Stack* s, element e);
element pop_stack(Stack* s);
void delete_stack(Stack* s);
void copy_stack(Stack* s, Stack* c);

#include "sstack.c"
#endif
