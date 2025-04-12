#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

int main()
{
    printf("Hello World\n");
    List lista;
    
    create_list(&lista);
    insertFirst_list(&lista, 231);
    insertEnd_list(&lista, 429);
    insertEnd_list(&lista, 32);
    insertEnd_list(&lista, 12);
    insertEnd_list(&lista, 5665);

    print_list(lista);
    printf("El elemento 12 se encuentra en %d", searchElement_list(&lista, 12));

    return 0;
}