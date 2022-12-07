/**
 * Linked List implementation in C
 * Author: Jason Kurtzman
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *newNode(int data)
{
    //Allocate the memory and returns pointer to memory
    struct node *createdNode = malloc(sizeof(struct node));
    //Ensure we successfully malloc-ed the node
    if(createdNode == NULL)
    {
        printf("ERROR MALLOC-ING NODE");
        exit(-1);
    }

    //If we successfuly made the node:
    createdNode->data = data;
    createdNode->next = NULL;
    return createdNode;
}

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
    struct node *node1 = newNode(1);
    struct node *node2 = newNode(2);
    struct node *node3 = newNode(3);
    node1->next = node2;
    node2->next = node3;
    printList(node1);
    struct node *node4 = newNode(4);
    appendNode(node1, node4);
    printList(node1);


    free(node1);
    free(node2);
    free(node3);
    free(node4);

    return 0;
}