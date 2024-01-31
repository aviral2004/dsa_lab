#include "linked_list.h"
#include "stack.h"
#include "heap_usage.h"
#include <stdlib.h>

typedef struct Stack {
    linked_list list;
} Stack;

Stack *newStack() {
    Stack *s = createNewList();
    return s;
}

bool push(Stack *s, Element e) {
    NODE n = createNewNode(e);
    insertNodeIntoList(n, s);
    return true;
}

void copy_elem(Element src, Element *dst) {
    dst->int_value = src.int_value;
    dst->float_value = src.float_value;
}

Element *pop(Stack *s) {
    if (s->head == NULL) {
        return NULL;
    }

    Element *e = (Element *) myalloc(sizeof(Element));
    e->int_value = s->head->data.int_value;
    e->float_value = s->head->data.float_value;
    removeFirstNode(s);
    return e;
}

bool isEmpty(Stack *s) {
    return s->head == NULL;
}

Element *top(Stack *s) {
    if (s->head == NULL) {
        return NULL;
    }

    Element *e = (Element *) myalloc(sizeof(Element));
    copy_elem(s->head->data, e);
    return e;
}

void freeStack(Stack *s) {
    while (s->head != NULL) {
        removeFirstNode(s);
    }

    myfree(s);
}