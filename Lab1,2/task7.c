#include <stdio.h>
#include <stdlib.h>

typedef struct node *NODE;
struct node
{
    int ele;
    NODE next;
};

typedef struct linked_list *LIST;
struct linked_list
{
    int count;
    NODE head;
};

LIST createNewList()
{
    LIST myList;
    myList = (LIST)malloc(sizeof(struct linked_list));
    myList->count = 0;
    myList->head = NULL;
    return myList;
}

NODE createNewNode(int value)
{
    NODE myNode;
    myNode = (NODE)malloc(sizeof(struct node));
    myNode->ele = value;
    myNode->next = NULL;
    return myNode;
}

void insertAfter(int searchEle, NODE n1, LIST l1)
{
    if (l1->head == NULL)
    {
        l1->head = n1;
        n1->next = NULL;
        l1->count++;
    }
    else
    {
        NODE temp = l1->head;
        NODE prev = temp;
        while (temp != NULL)
        {
            if (temp->ele == searchEle)
                break;
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("Element not found\n");
            return;
        }
        else
        {
            if (temp->next == NULL)
            {
                temp->next = n1;
                n1->next = NULL;
                l1->count++;
            }
            else
            {
                prev = temp;
                temp = temp->next;
                prev->next = n1;
                n1->next = temp;
                l1->count++;
            }
            return;
        }
    }
    return;
}

void printList(LIST l1)
{
    NODE temp = l1->head;
    printf("[HEAD] ->");
    while (temp != NULL)
    {
        printf(" %d ->", temp->ele);
        temp = temp->next;
    }
    printf(" [NULL]\n");
}