#include "sstack.h"

void create_stack(Stack *s)
{
    s -> top = -1;
}

int isFull_stack(Stack s)
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

int isEmpty_stack(Stack s)
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

void push_stack(Stack *s, element e)
{
    if(isFull_stack(*s))
    {
        printf("Error overflow\n");
    }
    else
    {
        s -> top ++;
        s -> st[s->top] = e;
    }
}

element pop_stack(Stack *s)
{
    element aux;
    if (isEmpty_stack(*s))
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

void delete_stack(Stack *s)
{
    while(!isEmpty_stack(*s))
    {
        element e = pop_stack(s);
    }
}

void copy_stack(Stack *s, Stack *c)
{
    Stack tmp;
    create_stack(&tmp);
    while (!isEmpty_stack(*s))
    {
        push_stack(&tmp, sPop(s));
    }
    while (!isEmpty_stack(tmp))
    {
        element e = pop_stack(&tmp);
        push_stack(s,e);
        push_stack(c,e);
    }
}
