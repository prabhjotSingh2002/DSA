

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
Problem-41 For a given K value (K > 0) reverse blocks of if nodes in a list.
Example: Input: 1 2 3 4 5 6 7 8 9 10, Output for different K values:
For K = 2: 2 1 4 3 6 5 8 7 10 9,
For K = 3: 3 2 1 6 5 4 9 8 7 10,
For K = 4: 4 3 2 1 8 7 6 5 9 10

Algorithm: This is an extension of swapping nodes in a linked list.
1) Check if remaining list has K nodes.
a. If yes get the pointer of K + 1
th node.
b. Else return.
2) Reverse first K nodes.
3) Set next of last node (after reversal) to K + 1
th node.
4) Move to K + 1
th node.
5) Go to step 1.
6) K – 1
th node of first K nodes becomes the new head if available. Otherwise, we can
return the head.



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

Node *getKplusOne(int k,Node *head);
int hasKNode(Node *head,int k);
Node *reverseBlockOfK(Node *head,int k);

void main()
{
    int op,k;
    Node *head=0;
    while(1)
    {
        printf("ENTER THE OPTION:\n");
        printf("1.add at end\n 2.add at begin \n 3.delete at end \n 4.delete from begin\n");
        printf("5.Display \n 6.clrscr\n 7.total count\n 8.info of nth node\n");
        printf("9.Reverse by k-block off\n");
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
            case 9:
                    printf("ENTER K: ");scanf("%d",&k);
                    head=reverseBlockOfK(head,k);
                    break;
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
    while(ptr  && c<20)
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

Node *getKplusOne(int k,Node *head)
{
    Node *kth=0;
    int i=0;
    if(!head)
    {
        return head;
    }

    for(i=0,kth=head;kth && (i<k);i++,kth=kth->next);

    if(i==k && kth!=NULL)
    {
        return kth;
    }
    return head;
}

int hasKNode(Node *head,int k)
{
    int i=0;
    for(i=0;head && (i<k);i++,head=head->next);
    if(i==k)
        return 1;
    return 0;
}

// Node *reverseBlockOfK(Node *head,int k)
// {
//     Node *cur=head,*temp=0,*next=0,*newHead=0,*ptr1=0;

//     int i;
//     if(k==0||k==1)
//     {
//         return head;
//     }
//     if(hasKNode(cur,k-1))
//     {
//             newHead=getKplusOne(k-1,cur);
//             printf("newhead data=%d\n",newHead->data);
//     }
//     else
//             newHead=head;
    
//     while(cur && hasKNode(cur,k))
//     {
        
//         temp=getKplusOne(k,cur);
//         printf("tempdata=%d\n",temp->data);
//         if(ptr1!=NULL)
//         {
//             ptr1->next=temp;
//         }
//         // printf("temp data=%d\n",temp->data);
//         ptr1=cur;
//         printf("ptrdata=%d  curdata=%d\n",ptr1->data,cur->data);
//         i=0;
//         while(i<k)
//         {
//             next=cur->next;
//             cur->next=temp;
//             temp=cur;
//             cur=next;
//             i++;
//         }
//     }

//     return newHead;
// }












Node *reverseBlockOfK(Node *head,int k)
{
    Node *cur=head,*temp=0,*next=0,*newHead=0,*ptr1=0,*refptr=0,*ptr2=0;

    int i;
    if(k==0||k==1)
    {
        return head;
    }
    if(hasKNode(cur,k-1))
    {
            newHead=getKplusOne(k-1,cur);
            printf("newhead data=%d\n",newHead->data);
    }
    else
            newHead=head;
    
    while(cur && hasKNode(cur,k))//cur initally head
    {
        
        ptr1=getKplusOne(k,cur);
        if(refptr!=NULL)
        {
            refptr->next=getKplusOne(k-1,cur);
        }
        printf("ptr1data=%d\n",ptr1->data);
        refptr=cur; 
        
        i=0;
        while(i<k)
        {
            ptr2=cur->next;
            cur->next=ptr1;
            ptr1=cur;
            cur=ptr2;
            i++;
        }
        if(ptr1==NULL)
            printf("PTR IS NULL\n");
        else
            printf("PTR data:%d\n",ptr1->data);


        // printf("temp data=%d\n",temp->data);
        // ptr1=cur;
        // printf("ptrdata=%d  curdata=%d\n",ptr1->data,cur->data);
        // i=0;
        // while(i<k)
        // {
        //     next=cur->next;
        //     cur->next=temp;
        //     temp=cur;
        //     cur=next;
        //     i++;
        // }
    }

    return newHead;
}

