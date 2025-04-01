#include <stdio.h>
#include "dstack.h"

int main()
{
        Node* ds;
        dCreate(&ds);
	dPush(&ds, 13);
        dPush(&ds, 24);
        dPrintStack(&ds);
        element e = dPop(&ds);
        printf("el numero 24: %d", e);
        return 0;
}
