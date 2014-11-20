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

QNode*
Q_push(Queue* Q, QNode* node)
{
  /* With first item in queue, there is nothing in front of it. */
  node->next = Q_is_empty(Q) ? NULL : Q->tail;

  if(Q_is_empty(Q))
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
  if(Q_is_empty(Q))
    return (QNode*) -1;

  QNode* popped_node;
  popped_node = Q->head;

  Q->head = Q->head->prev ? Q->head->prev : Q->tail;

  Q->head->next = NULL;

  Q->size--;
  return popped_node;
}

int
Q_is_empty(Queue* Q) { return (Q->size == 0); }

void
Q_inspect(Queue* Q)
{
  if (Q->size < 1){
    printf("Empty queue.\n");
    return;
  }

  QNode* cursor = Q->tail;
  const char *sep = "";

  printf("Queue: [");

  do {
    printf("%s%d", sep, cursor->data);
    cursor = cursor->next;
    sep = ", ";
  } while (cursor != Q->head);

  printf("]\n");
  printf("Size: %d\n", Q->size);
}

int
main()
{
  Queue Q;
  Q_create(&Q);

  int i;
  for (i = 0; i < 1000; i++) {
    QNode* a;
    a = QNode_create(i);
    Q_push(&Q, a);
  }

  int j;
  for (j = 0; j < 900; j++) {
    QNode* popped;
    popped = Q_pop(&Q);
  }

  Q_inspect(&Q);

  return true;
}
