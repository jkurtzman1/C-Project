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
    struct node *dummyHead = head;
    while(dummyHead -> next != NULL)
    {
        printf("%d -> ", dummyHead->data);
        dummyHead = dummyHead->next;
    }
    printf("%d\n", dummyHead->data);
}

// Add node to end of list
// Use when you don't know the last node of the list
// O(n)
void appendNode(struct node *head, struct node *nodeToAdd)
{
    struct node *dummyHead = head;
    while(dummyHead->next != NULL)
    {
        dummyHead = dummyHead -> next;
    }

    dummyHead -> next = nodeToAdd;
    nodeToAdd -> next = NULL;
}

// Add node at after a given node
void addAtPosition(struct node *nodeToAddAfter, struct node *nodeToAdd)
{
    nodeToAdd->next = nodeToAddAfter->next;
    nodeToAddAfter->next = nodeToAdd;
}

//Return a node's memory address
struct node *findNode(struct node *head, int toFind)
{
    struct node *dummyHead = head;
    while(dummyHead->next != NULL)
    {
        if(dummyHead->data == toFind)
        {
            return dummyHead;
        }
        dummyHead = dummyHead->next;
    }
    printf("ERR:COULD NOT FIND NODE");
    return NULL;
}

//Insert at head
//Takes head as double pointer so we can change the stored heads pointer in main through the use of this method rather than manually
void addAtHead(struct node **head, struct node *nodeToAdd)
{
    nodeToAdd -> next = *head;
    *head = nodeToAdd;
}

// Free the whole list at the end of the life of the list
void freeList(struct node *head)
{
    struct node *prev_node = head;
    while(head->next != NULL)
    {
        head = head->next;
        free(prev_node);
        prev_node = head;
    }
    free(head);
    //free(prev_node); //<- Causes double free() exception
}

int main()
{
    /*
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
    */

    struct node *head = newNode(0);
    struct node *tmp = NULL;
    for(int i = 1; i < 25; i++)
    {
        tmp = newNode(i);
        appendNode(head, tmp);
        //free(tmp);
    }
    printf("%p\n", findNode(head, 22));

    printList(head);
    printf("\n---------------\n");
    struct node *toAdd = newNode(255);
    addAtPosition(findNode(head, 22), toAdd);
    printList(head);

    struct node *newHeadNode = newNode(256);
    addAtHead(&head, newHeadNode);
    printf("\n---------------\n");
    printList(head);
    freeList(head);

    return 0;
}