/*
Problem-6 Can we solve Problem-5 with recursion? Solution: We can use a 
global variable to track the post recursive call and when it is same as Nth’,
return the node.
*/

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

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct node{
    int data;
    struct node *next;
}Node;


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
    while(ptr)
    {
        printf("%d. DATA: %d \n",++c,ptr->data);
        ptr=ptr->next;
    }
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

void info1(Node *hptr)
{
    int n;
    printf("Enter n: ");
    scanf("%d",&n);

    Node *ptr=hptr;
    Node *nptr=hptr;

    int c=0;

    while(ptr->next)
    {
        if(c>=n)
        {
            nptr=nptr->next;
        }
        c++;
        ptr=ptr->next;
    }

    if(c<n)
    {
        printf("fewer number of nodes in the list\n");
        return;
    }

    printf("DATA: %d \n",nptr->data);

}

int info2(Node *hptr,int n);

void main()
{
    int op,n;
    Node *head=0;
    while(1)
    {
        printf("ENTER THE OPTION:\n");
        printf("1.add at end\n 2.add at begin \n 3.delete at end \n 4.delete from begin\n");
        printf("5.Display \n6.clrscr\n7.total count\n8.info of nth node\n");
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
            case 8:printf("ENTER n: ");
                    scanf("%d",&n);
                    if(info2(head,n)==0)
                    {
                        printf("NOT FOUND\n");
                    }
                    
                    break;
            default:printf("NON-VALID OPTION\n");
        }

       // system("cls");
    }
}

int info2(Node *hptr,int n)
{
    static int counter=0;
    static int flag=0;
        if(hptr)
        {
            info2(hptr->next,n);
            if(counter<n)
                counter++;
            else if(n==counter)
            {
                flag=1;
                counter=0;
                printf("FOUND: %d\n",hptr->data);
                return flag;
            }
        }
    return flag;
}