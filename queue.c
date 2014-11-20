#include <stdio.h>
#include <stdlib.h>

#define true  (1)
#define false (0)


typedef struct QNode {
	int data;
	struct QNode* next;
	struct QNode* prev;
} QNode;


typedef struct Queue {
	int size;
	QNode* head;
	QNode* tail;
} Queue;


Queue*
Q_create(Queue* Q)
{
	Q->size = 0;
	Q->head = Q->tail;
	Q->tail = Q->head;

	return Q;
}


QNode*
QNode_create(int data)
{
	QNode* node;
	node = malloc(sizeof(QNode));

	node->data = data;
	node->prev = NULL;
	node->next = NULL;

	return node;
}


int
QNode_destroy(Queue* Q, QNode* node)
{
	if (node == NULL)
		return 0;
	
	if (node->next != NULL)
		node->next->prev = node->prev;

	if (node->prev != NULL)
		node->prev->next = node->next;

	free(node);
	node = NULL;
	Q->size--;

	return 1;
}


int
Q_is_empty(Queue* Q)
{
	return  Q->size == 0;
}


QNode*
Q_push(Queue* Q, int data)
{
	QNode* node;
	node = QNode_create(data);
	/* With first item in queue, there is nothing in front of it. */
	node->next = Q_is_empty(Q) ? NULL : Q->tail;

	if (Q_is_empty(Q))
		Q->head = node;
	else
		Q->tail->prev = node;

	/* Tail always points at end of queue */
	Q->tail = node;
	Q->size++;

	return node;
}


QNode*
Q_pop(Queue* Q)
{
	if (Q_is_empty(Q))
		return (QNode*) 0;

	QNode* popped_node;
	popped_node = Q->head;

	/* If we are are at the last item, head points to tail */
	Q->head = Q->head->prev ? Q->head->prev : Q->tail;

	Q->head->next = NULL;

	Q->size--;
	return popped_node;
}


Queue*
Q_teardown(Queue* Q)
{
	QNode* node;
	while ((node = Q_pop(Q)))
		free(node);
	
	return Q;
}


void
Q_inspect(Queue* Q)
{
	QNode* cursor = Q->tail;
	const char *sep = "\t";
	int counter = 0;

	printf("Queue:\n");

	if(Q_is_empty(Q)) printf("[]");

	while (cursor != Q->head) {
		printf("%s%d", sep, cursor->data);
		cursor = cursor->next;
		counter++;
		sep = (counter % 10 == 0) ? ",\n\t" :  ", ";
	}

	printf("\n\nSize: %d\n", Q->size);
}


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
