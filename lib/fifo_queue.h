#ifndef QUEUE_H_
#define QUEUE_H_

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

Queue* Q_teardown(Queue* Q);
Queue* Q_create(Queue* Q);
int Q_is_empty(Queue* Q);
void Q_inspect(Queue* Q);

QNode* QNode_create(int data);
QNode* Q_push(Queue* Q, int data);
QNode* Q_pop(Queue* Q);
int QNode_destroy(Queue* Q, QNode* node);

#endif
