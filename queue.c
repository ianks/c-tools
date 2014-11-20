#include <stdio.h>
#include <stdlib.h>

#define true  (1)
#define false (0)

typedef struct QNode {
  struct QNode *prev;
  struct QNode *next;
  int data;
} QNode;

typedef struct Queue {
  QNode* head;
  QNode* tail;
  int size;
} Queue;

Queue Q;

int
Q_create(Queue* Q)
{
  Q->head = Q->tail;
  Q->tail = Q->head;

  return true;
}

QNode*
Q_push(Queue* Q, QNode* node)
{
  /* Since this is a queue, there is nothing behind us upon insertion */
  node->next = Q->tail;
  node->prev = NULL;

  /* When the queue */
  if(Q->size == 0){
    Q->head = node;
    node->next = NULL;
  }

  else{
    Q->tail->prev = node;
  }

  Q->tail = node;

  Q->size++;
  return node;
}

QNode*
Q_pop(Queue* Q)
{
  if(Q->size < 1)
    return (QNode*) -1;

  QNode* popped_node;
  popped_node = Q->head;

  Q->head = Q->head->prev ? Q->head->prev : Q->tail;

  Q->head->next = NULL;

  Q->size--;
  return popped_node;
}

static inline int
Q_is_empty(Queue* Q) { return Q->size == 0; }

/* TODO: pass ref */
void
Q_inspect()
{
  if (Q.size < 1){
    printf("Empty queue.\n");
    return;
  }

  QNode* cursor = Q.tail;
  const char *sep = "";

  printf("Queue: [");

  do {
    printf("%s%d", sep, cursor->data);
    cursor = cursor->next;
    sep = ", ";
  } while (cursor != NULL);

  printf("]\n");
}

int
main()
{
  Q_create(&Q);

  int i;
  for (i = 0; i < 1000; i++) {
    QNode* a = malloc(sizeof(QNode));
    a->data = i;
    Q_push(&Q, a);
  }

  int j;
  for (j = 0; j < 900; j++) {
    Q_pop(&Q);
  }

  Q_inspect();

  return true;
}
