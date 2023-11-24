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
Problem-18 Suppose there are two singly linked lists both of which intersect at some point
and become a single linked list. The head or start pointers of both the lists are known, but
the intersecting node is not known. Also, the number of nodes in each of the lists before
they intersect is unknown and may be different in each list. List1 may have n nodes before
it reaches the intersection point, and List2 might have m nodes before it reaches the
intersection point where m and n may be m = n,m < n or m > n. Give an algorithm for
finding the merging point.
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

Node *recursiveReverse(Node *head)
{
    if(head->next==NULL ||head==NULL)
            return head;
    
    Node *rest=recursiveReverse(head->next);

    head->next->next=head;
    head->next=0;

    return rest;
}

void findMergingPoint(Node *head1,Node *head2)
{
    if(head1==0 || head2==0)
    {
        printf("ONE OF THE LL is empty\n");
        return;
    }

    Node *ptr1=head1;

    Node *arr[10]={0};
    int top=-1;

    while(ptr1)
    {
        top++;
        arr[top]=ptr1;
        ptr1=ptr1->next;
    }

    Node *ptr2=head2;

    while(ptr2)
    {
        //search
        int i;
        for(i=0;i<=top;i++)
        {
            if(arr[i]==ptr2)
            {
                printf("FOUND:at %d of second LL where data is %d \n",i,ptr2->data);
                return;
            }
        }
        printf("ptr2 data: %d\n",ptr2->data);
        ptr2=ptr2->next;
    }

    printf("NOT FOUND\n");
    return;

}

void findMergingPoint2(Node *head1,Node *head2)
{
    if(head1==0 || head2==0)
    {
        printf("ONE OF THE LL is empty\n");
        return;
    }

    Node *ptr1=head1;

    Node *arr1[10]={0};
    int top1=-1;

    Node *arr2[10]={0};
    int top2=-1;

    while(ptr1)
    {
        top1++;
        arr1[top1]=ptr1;
        ptr1=ptr1->next;
    }

    Node *ptr2=head2;

    while(ptr2)
    {
        top2++;
        arr2[top2]=ptr2;
        ptr2=ptr2->next;
    }

    while(top1>=0 && top2>=0)
    {
        printf("DATA at top1=%d DATA at top2=%d\n",(arr1[top1])->data,(arr2[top2])->data);
        if(arr1[top1]!=arr2[top2])
        {
            printf("FOUND\n");
            printf("POS FROM LL1: %d POS FROM LL2: %d data=%d\n",top1,top2,(arr1[top1])->data);
            return;
        }
        top1--;top2--;
    }

    printf("NOT FOUND\n");
    return;

}

void main()
{
    int op;
    Node *head1=0,*head2=0,*head=0;

    head1=calloc(1,sizeof(Node));
    head1->data=1;
    Node *ptr=head1;

    ptr->next=calloc(1,sizeof(Node));
    ptr=ptr->next;
    ptr->data=2;
    
    ptr->next=calloc(1,sizeof(Node));
    ptr=ptr->next;
    Node *ptr2=ptr;
    ptr->data=6;

    ptr->next=calloc(1,sizeof(Node));
    ptr=ptr->next;
    ptr->data=7;

    ptr->next=calloc(1,sizeof(Node));
    ptr=ptr->next;
    ptr->data=8;
    
    head2=calloc(1,sizeof(Node));
    head2->data=3;
    Node *qtr=head2;

    qtr->next=calloc(1,sizeof(Node));
    qtr=qtr->next;
    qtr->data=4;
    
    qtr->next=calloc(1,sizeof(Node));
    qtr=qtr->next;
    qtr->data=5;

    qtr->next=ptr2;

    while(1)
    {
        printf("ENTER THE OPTION:\n");
        printf("1.add at end\n 2.add at begin \n 3.delete at end \n 4.delete from begin\n");
        printf("5.Display \n 6.clrscr\n 7.total count\n 8.info of nth node\n9)reverse link\n");
        printf("10)findMergingPoint\n");
        printf("op: ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:addEnd(&head);break;
            case 2:addBeg(&head);break;
            case 3:delEnd(&head);break;
            case 4:delBeg(&head);break;
            case 5:display(head2);break;
            case 6:system("cls");break;
            case 7:printf("count =%d\n",count(head));break;
            case 8:info(head);break;
            case 9:head=recursiveReverse(head);break;
            case 10: findMergingPoint2(head1,head2);break;
            default:printf("Entered wrong option\n");
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

