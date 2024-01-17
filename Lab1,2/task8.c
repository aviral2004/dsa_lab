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

void insertFirst(LIST l, NODE n) {
    NODE first = l->head;
    l->head = n;
    n->next = first;
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

void shift(LIST l) {
    NODE first = l->head;
    l->head = first->next;

    NODE tmp = l->head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = first;
    tmp->next->next = NULL;
}


void bad_rotate(LIST l, int k) {
    for (int i = 0; i < k; i++) {
        shift(l);
    }
}

// O(k) solution
void rotate(LIST l, int k) {
    NODE tmp = l->head;
    NODE last_node = NULL;

    int counter = 1;
    while (tmp->next != NULL) {
        if (counter == k) {
            last_node = tmp;
        }
        tmp = tmp->next;
        counter++;
    }

    if (last_node != NULL) {
        tmp->next = l->head;
        l->head = last_node->next;
        last_node->next = NULL;
    }
}

void reverse(LIST l) {
    NODE prev = NULL;
    NODE current = l->head;
    NODE next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    l->head = prev;
}

int hasCycle(LIST l) {
    if (l->head == NULL) {
        return 0;
    }

    NODE tort = l->head;
    NODE hare = l->head->next;
    while (tort != NULL && hare != NULL) {
        if (tort == hare) {
            return 1;
        }
        tort = tort->next;
        hare = hare->next->next;
    }

    return 0;
}

int main() {
    LIST l1 = createNewList();
    insertFirst(l1, createNewNode(3));
    insertFirst(l1, createNewNode(2));
    insertFirst(l1, createNewNode(1));
    printf("Has cycle: %d\n", hasCycle(l1));  // Should print 0

    LIST l2 = createNewList();
    NODE node = createNewNode(1);
    insertFirst(l2, node);
    insertFirst(l2, createNewNode(2));
    insertFirst(l2, node);  // Create a cycle
    printf("Has cycle: %d\n", hasCycle(l2));  // Should print 1

    LIST l3 = createNewList();
    node = createNewNode(1);
    insertFirst(l3, node);
    node->next = node;  // Create a circular list
    printf("Has cycle: %d\n", hasCycle(l3));  // Should print 1

    return 0;
}