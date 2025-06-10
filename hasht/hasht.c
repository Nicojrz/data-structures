#include "hasht.h"

void create_table(HashTable *t)
{
	int i;
	t->num = 0;
	
	for(i=0; i<M; i++)
	{
		t->Table[i] = NULL;
	}
}

void insert_table(HashTable *t, element e)
{
	element *new;
	int p = get_index(*t, e.key);
	
	new = (element *)malloc(sizeof(element));
	new->key = e.key;
	
	t->Table[p] = new;
	t->num++;
}

element *search_table(HashTable t, int key)
{
	int p = get_index(t, key);
	return t.Table[p];
}

element delete_table(HashTable *t, int key)
{
	element *ptr, elem;
	int p = get_index(*t, key);
	
	ptr = t->Table[p];
	
	if(ptr != NULL)
	{
		elem = *ptr;
		t->Table[p] = NULL;
		
		free(ptr);
		t->num--;
	}
	else
	{
		elem.key = -1;
	}
	
	return elem;
}

int get_index(HashTable t, int key)
{
	int i;
	int p = key % M;
	
	if(t->Table[p] != NULL)
	{
		for(i=1; i<M; i++)
		{
			p = p+i;
			p = p%M;
			
			if(t->Table[p] == NULL)
			{
				break;
			}
		}		
	}
	
	return p;
}