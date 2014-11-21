#include "../lib/fifo_queue.h"
#include <stdlib.h>
#include <stdio.h>

int
main()
{
	Queue Q;
	Q_create(&Q);

	int i;
	for (i = 0; i < 1000; i++)
		Q_push(&Q, i);

	Q_inspect(&Q);
	Q_teardown(&Q);
	Q_inspect(&Q);

	return EXIT_SUCCESS;
}
