#include <stdio.h>
#include "sstack.h"

int main()
{
	int opc = 0;
	Stack s;
	sCreate(&s);

	do
	{
		printf("MENU\n1.Pop\n2.Push\n3.Imprimir\n4.Salir\n");
		printf("Ingresa una opcion...\n");
		scanf("%d", &opc);

		switch(opc)
		{
			case 1:
				if(sIsEmpty(s))
				{
					printf("La pila esta vacia.\n");
				}
				else
				{			
					element e = sPop(&s);
					printf("Elemento eliminado: %d\n", e);
				}
				break;
			case 2:
				if(sIsFull(s))
				{
					printf("La pila esta llena, elimina un elemento.\n");
				}
				else
			{
					element e;
					printf("Ingresa un elemento...\n");
					scanf("%d", &e);
					sPush(&s, e);
				}
				break;
			case 3:
				printf("Imprimiendo pila.\n");
				
				if(sIsEmpty(s))
				{
					printf("La pila esta vacia.\n");
				}
				else
				{
					Stack c;
					sCreate(&c);
					sCopyStack(&s, &c);
					while(!sIsEmpty(c))
					{
						element e = sPop(&c);
						printf("%d\n", e);
					}
				}
				break;
			case 4:
				sDelete(&s);
				printf("Adios! Pila eliminada.\n");
				break;
			default:
				printf("Ingresa una opcion valida\n");
				break;
		}
	}
	while(opc != 4);
}
