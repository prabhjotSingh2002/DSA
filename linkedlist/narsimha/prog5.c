/*
Problem-2 Find nth node from the end of a Linked List.
Solution: Brute-Force Method: Start with the first node and count the number of nodes 
present after that node. If the number of nodes is < n – 1 then return saying 
“fewer number of nodes in the list”. If the number of nodes is
 > n – 1 then go to next node. 
 Continue this until the numbers of nodes after current node are n – 1. 
 Time Complexity: O(n2), for scanning the remaining list (from current node) for each node. 
Space Complexity: O(1)
*/

/*
Problem-7 Check whether the given linked list is either NULL-terminated
 or ends in a cycle (cyclic)

Solution: Brute-Force Approach. As an example, consider the following linked list 
which has a loop in it. 
The difference between this list and the regular list is that, in this list,
there are two nodes whose next pointers are the same. In regular singly linked lists (without a loop) each node’s next pointer is unique.
That means the repetition of next pointers indicates the existence of a loop.

One simple and brute force way of solving this is, start with the first node and 
see whether there is any node whose next pointer is the current node’s address. 
If there is a node with the same address then that indicates that some
other node is pointing to the current node and we can say a loop exists. 
Continue this process for all the nodes of the linked list.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

void addEnd(Node **hptr);
void addBeg(Node **hptr);
void delEnd(Node **hptr);
void delBeg(Node **hptr);
int count(Node *hptr);
void info(Node *hptr);
void display(Node *hptr);




void main()
{
    int op;
    Node *head=0;
    Node *ptr=malloc(sizeof(Node));
    ptr->data=1;
    head=ptr;

    ptr->next=malloc(sizeof(Node));
    ptr=ptr->next;
    ptr->data=2;

    ptr->next=malloc(sizeof(Node));
    ptr=ptr->next;
    Node *ptr1=ptr;
    ptr->data=3;

    ptr->next=malloc(sizeof(Node));
    ptr=ptr->next;
    ptr->data=4;

    ptr->next=malloc(sizeof(Node));
    ptr=ptr->next;
    ptr->data=5;

    ptr->next=malloc(sizeof(Node));
    ptr=ptr->next;
    ptr->data=6;

    ptr->next=malloc(sizeof(Node));
    ptr=ptr->next;
    ptr->data=7;

    ptr->next=malloc(sizeof(Node));
    ptr=ptr->next;
    ptr->data=8;
    ptr->next=ptr1;

    while(1)
    {
        printf("ENTER THE OPTION:\n");
        printf("1.add at end\n 2.add at begin \n 3.delete at end \n 4.delete from begin\n");
        printf("5.Display \n 6.clrscr\n 7.total count\n 8.info of nth node\n");
        printf("op: ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:addEnd(&head);break;
            case 2:addBeg(&head);break;
            case 3:delEnd(&head);break;
            case 4:delBeg(&head);break;
            case 5:display(head);break;
            case 6:system("cls");break;
            case 7:printf("count =%d\n",count(head));break;
            case 8:info(head);break;

        }
    }
}

void addEnd(Node **hptr)
{
    Node *new=malloc(sizeof(Node));
    printf("Enter data: ");
    scanf("%d",&new->data);

    new->next=0;

    if(*hptr==0)
    {
        *hptr=new;
        printf("Data added\n");
        return; 
    }

    Node *ptr=*hptr;
    while(ptr->next)
    {
        ptr=ptr->next;
    }
    ptr->next=new;
    printf("Data added\n");
}

void addBeg(Node **hptr)
{
    Node *new=malloc(sizeof(Node));
    printf("Enter data: ");
    scanf("%d",&new->data);
    
    if(*hptr==0)
    {
        new->next=*hptr;
        *hptr=new;
         printf("Data added\n");
         return;
    }

    new->next=*hptr;
    *hptr=new;
    printf("Data added\n");

}

void delEnd(Node **hptr)
{
    if(*hptr==0)
    {
        printf("No record\n");
        return;
    }
    if((*hptr)->next==0)
    {
        free(*hptr);
        *hptr=0;
        return;
    }
    Node *ptr=*hptr;
    Node *prev=0;
    while(ptr->next)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    free(ptr);
    prev->next=0;
}

void delBeg(Node **hptr)
{
    if(*hptr==0)
    {
        printf("No record\n");
        return;
    }
    if((*hptr)->next==0)
    {
        free(*hptr);
        *hptr=0;
        return;
    }
    Node *ptr=*hptr;
    *hptr=(*hptr)->next;
    ptr->next=0;
    free(ptr);

}

void display(Node *hptr)
{
    if(hptr==0)
    {
        printf("No Record\n");
        return;
    }
    Node *ptr=hptr;
    int c=0;

    Node *hptr1=ptr;
    Node *ptr1=hptr1;
    
    while(ptr)
    {
        //search
       ptr=ptr->next;
    }
    /*while(ptr)
    {
        printf("%d. DATA: %d \n",++c,ptr->data);
        ptr=ptr->next;
    }*/
}

int count(Node *hptr)
{
    int c=0;
    Node *ptr=hptr;
    while(ptr)
    {
        ptr=ptr->next;
        c++;
    }
    return c;
}


void info(Node *hptr)
{
    int n;
    printf("Enter N: ");
    scanf("%d",&n);
    int c=count(hptr);
    if(c<n-1)
    {
            printf("fewer number of nodes in the list\n");
            return;
    }
    int i=0;
    Node *ptr=hptr;
    for(i=0;i<c-n;i++)
    {
        ptr=ptr->next;
    }
    printf("DATA FOUND:)  %d\n",ptr->data);
}