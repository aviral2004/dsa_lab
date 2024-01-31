#include "element.h"
#include "queue.h"
#include "heap_usage.h"
#include <stdlib.h>

#define HEAP_SIZE 1000
typedef struct Queue
{
    int front;
    int size;
    Element data[HEAP_SIZE];
} Queue;

Queue *newQueue(){
    Queue *q = (Queue *) myalloc(sizeof(Queue));
    if (q != NULL) {
        q->front = 0;
        q->size = 0;
    }
    return q;
}

bool enqueue(Queue *q, Element e) {
    if (q->size == HEAP_SIZE)
        return false;

    q->data[(q->front + q->size) % HEAP_SIZE] = e;
    q->size++;
    return true;
}

bool dequeue(Queue *q) {
    if (q->size == 0)
        return false;

    q->front = (q->front + 1) % HEAP_SIZE;
    q->size--;
    return true;
}

Element *front(Queue *q) {
    if (q->size == 0)
        return NULL;

    return q->data + q->front;
}

int size(Queue *q) {
    return q->size;
}

bool isEmpty(Queue *q) {
    return q->size == 0;
}

void destroyQueue(Queue *q) {
    myfree(q);
}