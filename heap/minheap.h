#ifndef MINHEAP
#define MINHEAP

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct Heap
{
    int size;
    int last;
    element *array;
} Heap;

void createMinheap(Heap *h, int s);
void insertMinheap(Heap *h, element e);
element removeMinheap(Heap *h);
void deleteMinheap(Heap *h);

void upheap(Heap *h, int child);
void downheap(Heap *h, int parent);

int getLeftChild(int n);
int getRightChild(int n);
int getParent(int n);

void resizeMinheap(Heap *h);

#endif