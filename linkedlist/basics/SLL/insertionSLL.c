#include"../Header.h"
#include "SLLheader.h"
/*
Insertion into a singly-linked list has three cases:
• Inserting a new node before the head (at the beginning) 
• Inserting a new node after the tail (at the end of the list) 
• Inserting a new node at the middle of the list (random location)
*/

void insertInLinkedList(struct listnode ** head,int data,int pos)
{
    int k=1;
    struct listnode *p,*q,*newNode;

    newNode=(struct listnode*)malloc(sizeof(struct listnode));

    if(!newNode)
    {
        printf("Memory error");
        return;
    }

    newNode->data=data;
    p=*head;

    if(pos==1) //inserting at head
    {
        newNode->next=p;
        *head=newNode;
    }
    else
    {
        //traverse the list until we reach position we want to insert

        while((p!=NULL) &&(k<pos))
        {
            k++;
            q=p;
            p=p->next;
        }

        q->next=newNode;
        newNode->next=p;
    }
    return;
}
/*
Time Complexity: O(n), since, in the worst case, we may need to insert the node at the end of the list.
 Space Complexity: O(1), for creating one temporary variable
*/