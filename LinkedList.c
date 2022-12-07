/**
 * Linked List implementation in C
 * Author: Jason Kurtzman
*/

#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

void printList(struct node *head)
{
    while(head -> next != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("%d\n", head->data);
}

// Add node to end of list
void appendNode(struct node *head, struct node *nodeToAdd)
{
    while(head->next != NULL)
    {
        head = head -> next;
    }

    head -> next = nodeToAdd;
    nodeToAdd -> next = NULL;
}

int main()
{
    struct node node1 = {1, NULL};
    printList(&node1);
    struct node node2 = {2, NULL};
    appendNode(&node1, &node2);
    printList(&node1);
    struct node node3 = {3, NULL};
    appendNode(&node1, &node3);
    printList(&node1);
    struct node node4 = {4, NULL};
    appendNode(&node1, &node4);
    printList(&node1);
    return 0;
}