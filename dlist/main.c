#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

int main()
{
    printf("Hello World\n");
    List lista;
    
    create_list(&lista);
    insertFirst_list(&lista, 231);
    insertFirst_list(&lista, 429);
    print_list(lista);

    return 0;
}
