#include "element.h"
#include <stdlib.h>
#include "heap_usage.h"

struct node
{
    Element data;
    struct node *next;
};
typedef struct node node;
typedef node *NODE;

struct linked_list
{
    int count;
    NODE head;
    // NODE tail; // Not required for stack. Required for Queue
};
typedef struct linked_list linked_list;
typedef linked_list *LIST;

LIST createNewList()
{
    LIST myList = (LIST) myalloc(sizeof(linked_list));
    myList->count = 0;
    myList->head = NULL;
    return myList;
}


NODE createNewNode(Element value)
{
    NODE myNode = (NODE) myalloc(sizeof(struct node));
    myNode->data = value;
    myNode->next = NULL;
    return myNode;
}

void insertNodeIntoList(NODE node, LIST list) {
    node->next = list->head;
    list->head = node;
    list->count++;
}

void removeFirstNode(LIST list) {
    NODE tmp = list->head;
    list->head = list->head->next;
    myfree(tmp);
    list->count--;
}

void insertNodeAtEnd(NODE node, LIST list) {
    if (list->head == NULL) {
        list->head = node;
    }

    NODE tmp = list->head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = node;
    list->count++;
}