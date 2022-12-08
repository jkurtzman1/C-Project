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

//Delete node from list
//Need to take double pointer for head to change head outside of main when deleting head node.
void deleteNode(struct node **head, struct node *nodeToDelete)
{
    struct node *dummyHead = *head;
    if(nodeToDelete == dummyHead) //Deleting head, so change head pointer
    {
        *head = dummyHead->next;
    }else   //Middle or end of list
    {
        //Traverse the Linked List
        while(dummyHead->next != nodeToDelete)
        {
            dummyHead = dummyHead -> next;
        }

        //If we are deleting at end:
        if(nodeToDelete->next == NULL)
        {
            dummyHead->next = NULL;
        }else //If we are deleting in middle:
        {
            dummyHead->next = dummyHead->next->next;
        }
    }
    free(nodeToDelete);
}

//Return a node's memory address
struct node *findNode(struct node *head, int toFind)
{
    struct node *dummyHead = head;
    while(dummyHead != NULL)
    {
        if(dummyHead->data == toFind)
        {
            return dummyHead;
        }
        dummyHead = dummyHead->next;
    }
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
    for(int i = 1; i < 11; i++)
    {
        tmp = newNode(i);
        appendNode(head, tmp);
        //free(tmp);
    }
    printf("%p\n", findNode(head, 10));

    printList(head);
    printf("\n---------------\n");
    struct node *toAdd = newNode(255);
    addAtPosition(findNode(head, 2), toAdd);
    printList(head);

    struct node *newHeadNode = newNode(256);
    addAtHead(&head, newHeadNode);
    printf("\n---------------\n");
    printList(head);

    printf("\n---------------\n");
    deleteNode(&head, findNode(head, 6));
    deleteNode(&head, head);
    deleteNode(&head, findNode(head, 9));
    printList(head);

    printf("\n---------------\n");
    deleteNode(&head, findNode(head, 10));
    printList(head);


    freeList(head);

    return 0;
}