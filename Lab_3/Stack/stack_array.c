#include "element.h"
#include "stack.h"
#include <stdlib.h>
#include "heap_usage.h"

#define STACK_SIZE 1000
struct Stack
{
    int top;
    Element data[STACK_SIZE];
};
typedef struct Stack Stack;

Stack *newStack()
{
    Stack *s = (Stack *) myalloc(sizeof(Stack));
    if (s != NULL)
        s->top = -1;
    return s;
}

bool push(Stack *s, Element e)
{
    if (s->top == STACK_SIZE - 1)
        return false;
    s->data[++(s->top)] = e;
    return true;
}

Element *pop(Stack *s) {
    if (s->top == -1)
        return NULL;
    
    Element *e = s->data + s->top;
    s->top--;
    return e;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

Element *top(Stack *s) {
    if (s->top == -1)
        return NULL;

    return s->data + s->top;
}

void freeStack(Stack *s) {
    myfree(s);
}