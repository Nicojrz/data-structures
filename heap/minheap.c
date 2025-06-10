#include "minheap.h"

void createMinheap(Heap *h, int s)
{
    h->size = s;
    h->last = -1;
    h->array = (element *)malloc(sizeof(element) * h->size);
}

void insertMinheap(Heap *h, element e)
{
    if(h->last == h->size-1)
    {
        resizeMinheap(h);
    }
    else
    {
        h->last++;
        h->array[h->last] = e;
        upheap(h, h->last);
    }
}

element removeMinheap(Heap *h)
{
    if(h->last < 0)
    {
        fprintf(stderr, "Heap is empty.\n");
        exit(1);
    }
    
    element min = h->array[0];
    h->array[0] = h->array[h->last];
    h->last--;
    downheap(h, 0);
    
    return min;
}

void deleteMinheap(Heap *h)
{
    free(h->array);
    h->array = NULL;
    h->size = 0;
    h->last = -1;
}

void upheap(Heap *h, int child)
{
    int parent = getParent(child);
    while(child > 0 && h->array[child] < h->array[parent])
    {
        element temp = h->array[child];
        h->array[child] = h->array[parent];
        h->array[parent] = temp;
        
        child = parent;
        parent = getParent(child);
    }
}

void downheap(Heap *h, int parent)
{
    int left = getLeftChild(parent);
    int right = getRightChild(parent);
    int smallest = parent;

    if(left <= h->last && h->array[left] < h->array[smallest])
    {
        smallest = left;
    }
    
    if(right <= h->last && h->array[right] < h->array[smallest])
    {
        smallest = right;
    }
    
    if(smallest != parent)
    {
        element temp = h->array[parent];
        h->array[parent] = h->array[smallest];
        h->array[smallest] = temp;
        
        downheap(h, smallest);
    }
}

int getLeftChild(int n)
{
    return 2*n + 1;
}

int getRightChild(int n)
{
    return 2*n + 2;
}

int getParent(int n)
{
    if(n == 0)
    {
        return -1;
    }
    return (n - 1) / 2;
}

void resizeMinheap(Heap *h)
{
    h->size *= 2;
    h->array = (element *)realloc(h->array, sizeof(element) * h->size);
}