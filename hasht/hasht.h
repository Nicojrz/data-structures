#ifndef HASHT
#define HASHT

#include <stdio.h>
#include <stdlib.h>

#define M 32

typedef struct element
{
	int key;
	int e;
} element;

typedef struct HashTable
{
	element *Table[M];
	int num;
} HashTable;

void create_table(HashTable *t);
void insert_table(HashTable *t, element e);
element *search_table(HashTable t, int key);
element delete_table(HashTable *t, int key);
int get_index(HashTable t, int key);

#endif