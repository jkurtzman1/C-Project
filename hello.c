#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

void printList(struct node *head)
{
    while(head->next != NULL)
    {
        printf("%d -> ", head->data);
        head = head -> next;
    }
    printf("%d\n", head->data);
}

void appendNode(struct node *headNode, struct node *toAppend)
{
    //Get last node
    struct node *lastNode = headNode;
    while(lastNode->next != NULL)
    {
        lastNode = lastNode -> next;
    }
    lastNode->next = toAppend;
    toAppend->next = NULL;
}

struct node* findNode(struct node *head, int dataToFind, int status)
{
    while(head -> next != NULL)
    {
        if(head -> data == dataToFind)
        {
            if(status == 1) printf("FOUND %d @ %p\n", dataToFind, head);
            return head;
        }else
        {
            head = head->next;
        }
    }
    if(status == 1) printf("ERR::COULD NOT FIND NODE\n");
    return NULL;
}

void deleteNode(struct node *nodeToDelete)
{

}

int main()
{
    struct node node1;
    struct node node2;
    struct node node3;
    node1.data = 1;
    node2.data = 2;
    node3.data = 3;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;

    printList(&node1);

    struct node node4;
    node4.data = 4;
    appendNode(&node1, &node4);

    printList(&node1);

    struct node *found = findNode(&node1, 3, 1);
}