#include "dstack.h"

void create_dstack(node** s)
{
    *s = NULL;
}

int isEmpty_dstack(node* s)
{
    if(s == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push_dstack(node** s, element e)
{
    node* new = (node*)malloc(sizeof(node));
    if(new == NULL)
    {
	printf("Error memoria dPush.\n");
    }
    new->e = e;
    new->next = *s;
    *s = new;
}

element pop_dstack(node** s)
{
    element eaux;
    if(!isEmpty_dstack(*s))
    {
        eaux = (*s)->e;
        node* saux = (*s);
        *s = (*s)->next;
        free(saux);
    }
    else
    {
        eaux = 0;
        printf("Error underflow\n");
    }
    return eaux;
}

void delete_dstack(node** s)
{
    while(!isEmpty_dstack(*s))
    {
        element e = pop_dstack(s);
    }
}

void print_dstack(node** s)
{
    node* aux = NULL;
    element e;

    while(!isEmpty_dstack(*s))
    {
        e = pop_dstack(s);
        push_dstack(&aux,e);
	printf("%d", e);
    }
    while(!isEmpty_dstack(aux))
    {
        e = pop_dstack(&aux);
        push_dstack(s,e);
    }
    printf("\n");
}
