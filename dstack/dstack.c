#include "dstack.h"

void dCreate(Node** s)
{
    *s = NULL;
}

int dIsEmpty(Node* s)
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

void dPush(Node** s, element e)
{
    Node* new = (Node*)malloc(sizeof(Node));
    if(new == NULL)
    {
	printf("Error memoria dPush.\n");
    }
    new->e = e;
    new->next = *s;
    *s = new;
}

element dPop(Node** s)
{
    element eaux;
    if(!dIsEmpty(*s))
    {
        eaux = (*s)->e;
        Node* saux = (*s);
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

void dDelete(Node** s)
{
    while(!dIsEmpty(*s))
    {
        element e = dPop(s);
    }
}

void dPrintStack(Node** s)
{
    Node* aux = NULL;
    element e;

    while(!dIsEmpty(*s))
    {
        e = dPop(s);
        dPush(&aux,e);
    }
    while(!dIsEmpty(aux))
    {
        e = dPop(&aux);
        printf("%d\n", e);
        dPush(s,e);
    }
}
