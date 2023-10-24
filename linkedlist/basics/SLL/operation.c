#include "../Header.h"
#include "SLLheader.h"

struct listnode **head=NULL;

void inserting()
{
    int data;
    printf("enter data:\n");
    scanf("%d",&data);

    printf("1. give pos\n 2.insert at end\n");
    int op1;
    scanf("%d",&op1);
         
    if(op1==1)
    {
        int pos;
        printf("enter pos:\n");
        scanf("%d",&pos);

        if(pos<0 && pos>ListLength(head))
        {
            printf("enter valid pos:\n");
            return;
        }
        insertInLinkedList(head,data,pos);

    }
    else if(op1==2)
    {
          insertInLinkedList(head,data,ListLength(head));
    }
    else
    {
        printf("enter valid op:\n");
    }
    return;
}

void deleting()
{
    printf("1. to enter pos/n2.to delete from last");
    int op3;
    scanf("%d",&op3);

    if(op3==1)
    {
        int pos;
        printf("enter pos:\n");
         scanf("%d",&pos);

        if(pos<0 && pos>ListLength(head))
        {
            printf("enter valid pos:\n");
            return;
        }
        DeletingNodeFromLinkedList(head,pos);
    }
    else if(op3==2)
    {
        DeletingNodeFromLinkedList(head,ListLength(head));
    }
    else
    {
        printf("enter valid op\n");
    }
    return;
}

void length()
{
    printf("length of the list:%d\n",ListLength(head));
    return;
}

void truncate()
{
     DeletionLinkedList(head);
     printf("LIST HAS BEEN TRUNCATED\n");
     return;
}