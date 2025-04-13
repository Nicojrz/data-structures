#include "dqueue.h"

int main()
{
	DQueue cola;
	create_dqueue(&cola);
	
	printf("%d\n", isEmpty_dqueue(cola));
	
	enqueue_dqueue(&cola, 12);
	enqueue_dqueue(&cola, 32);
	enqueue_dqueue(&cola, 45);
	enqueue_dqueue(&cola, 325);
	
	print_dqueue(&cola);
	
	element e = dequeue_dqueue(&cola);
	e = dequeue_dqueue(&cola);
	
	print_dqueue(&cola);
	
	delete_dqueue(&cola);
	
	return 0;
}