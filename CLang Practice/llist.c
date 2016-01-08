#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

NODE* createNode(int data)
{
    NODE* new = (NODE *)malloc(sizeof(NODE*));
    if(new == NULL)
        return NULL;
        
    new->data = data;
    new->next = NULL;
    
    return new;
}

void printList(NODE* head)
{
    NODE* curr = head;
    if(curr == NULL)
        return;
    printf("******BEGIN*****\n");
    while(curr != NULL)
    {
        printf("%d\n",curr->data);
        curr = curr->next;
    }
    printf("*******END******\n\n");
    return;
}

void insertFront(NODE** head,int data)
{
    NODE* curr = *head;
    if (curr == NULL)
    {
        NODE* new = createNode(data);
        *head = new;
    }
    else
    {
        NODE* new = createNode(data);
        new->next = *head;
        *head = new;
    }
    return;
}

void insertAfter(NODE* head,NODE* node,int data)
{
    if(node == NULL || head == NULL)
        return;
    
    NODE* curr = head;
    while(curr)
    {
        if(curr == node)
        {
            NODE* new = createNode(data);
            new->next = curr->next;
            curr->next = new;
            return;
        }
        curr = curr->next;
    }
    return;
}

void insertTail(NODE* head,int data)
{
    NODE* new = createNode(data);
    if(head == NULL)
    {
        head = new;
    }
    else
    {
        NODE* curr = head;
        while(curr->next != NULL)
            curr = curr->next;
        
        curr->next = new;
    }
    return;
}

void deleteNode(NODE* delNode)
{
    if(delNode == NULL)
        return;
    
    NODE* delNext = delNode->next;
    delNode->data = delNext->data;
    delNode->next = delNext->next;
    return;
}

void deleteNodeWithKey(NODE** head,int data)
{
    NODE* curr = *head;
    
    if(curr == NULL)
        return;
    if(curr->data == data)
    {
        NODE* temp = curr->next;
        *head = temp;
    }
    else
    {
        while(curr->next != NULL)
        {
            if (curr->next->data == data)
            {
                NODE* nextNext = curr->next->next;
                NODE* temp = curr->next;
                curr->next = nextNext;
                free(temp);
                return;
            }
            curr = curr->next;
        }
    }
    return;
}

int main()
{
    NODE *head = NULL;
    
    head = createNode(1);
    NODE* second = createNode(2);
    NODE* third = createNode(3);
    
    head->next = second;
    second->next = third;
    
    printList(head);
    
    insertFront(&head,4);
    
    printList(head);
    
    insertAfter(head,third,5);
    
    printList(head);
    
    insertTail(head,6);
    
    printList(head);
    
    deleteNode(third);
    printList(head);
    
    deleteNodeWithKey(&head,4);
    deleteNodeWithKey(&head,6);
    printList(head);
    

    return 0;
}

