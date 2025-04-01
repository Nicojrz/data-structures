#include "sstack.h"

void sCreate(Stack* s)
{
    s -> top = -1;
}

int sIsFull(Stack s)
{
    if(s.top == (SIZE - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int sIsEmpty(Stack s)
{
    if(s.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void sPush(Stack* s, element e)
{
    if(sIsFull(*s))
    {
        printf("Error overflow\n");
    }
    else
    {
        s -> top ++;
        s -> st[s->top] = e;
    }
}

element sPop(Stack* s)
{
    element aux;
    if (sIsEmpty(*s))
    {
        printf("Error underflow\n");
        aux = 0;
    }
    else
    {
        aux = s -> st[s -> top];
	s->top--;
    }
    return aux;
}

void sDelete(Stack* s)
{
    while(!sIsEmpty(*s))
    {
        element e = sPop(s);
    }
}

void sCopyStack(Stack* s, Stack* c)
{
    Stack tmp;
    sCreate(&tmp);
    while (!sIsEmpty(*s))
    {
        sPush(&tmp, sPop(s));
    }
    while (!sIsEmpty(tmp))
    {
        element e = sPop(&tmp);
        sPush(s,e);
        sPush(c,e);
    }
}
