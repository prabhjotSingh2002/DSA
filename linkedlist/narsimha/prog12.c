//Problem-25 How will you find the middle of the linked list?

/*
: Efficient Approach: Use two pointers. Move one pointer 
at twice the speed of the
second. When the first pointer reaches the end of the
 list, the second pointer will be pointing to
the middle node.
Note: If the list has an even number of nodes, 
the middle node will be of [n/2].

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

//problem 28:backward recursive print

//problem 29:check wheter the given LL length is
// even or odd


// Use a 2x pointer. Take a pointer that moves
//at 2x [two nodes at a time]. At the end, if
//the length is even, then the pointer will be NULL;
//otherwise it will point to the last node.

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
Node *findMiddle(Node *head);
void printListRec(Node *head);
int iSLLlengthEven(Node *head);




void main()
{
    int op;
    Node *head=0;
    Node *ptr=0;
    while(1)
    {
        printf("ENTER THE OPTION:\n");
        printf("1.add at end\n 2.add at begin \n 3.delete at end \n 4.delete from begin\n");
        printf("5.Display \n 6.clrscr\n 7.total count\n 8.info of nth node\n9.find mid\n");
        printf("10)backward print\n11)check if list length is even\n");
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
            case 9:ptr=findMiddle(head);
                    printf("middle data=%d\n",ptr->data);
                    break;
            case 10: printListRec(head);break;
            case 11:if(iSLLlengthEven(head)==0)
                    {
                        printf("EVEN Length\n");
                    }
                    else
                        printf("ODD LENGTH\n");
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

Node *findMiddle(Node *head)
{
    Node *ptr1=0,*ptr2=0;
    ptr1=ptr2=head;
    int i=0;

  //keep looping until we reach the tail(next will
  //be NULL for the last node)

    while(ptr1->next!=NULL)
    {
        if(i==0)
        {
            //increment only the 1st pointer
            ptr1=ptr1->next;
            i=1;
        }
        else if(i==1)
        {
            //increment 
            ptr1=ptr1->next;
            ptr2=ptr2->next;
            i=0;
        }
    }
    return ptr2;

}

void printListRec(Node *head)
{
    if(!head)
        return;

    printListRec(head->next);
    printf("%d\n",head->data);
}

int iSLLlengthEven(Node *head)
{
    while(head && head->next)
        head=head->next->next;


    if(!head)
        return 0;

    return 1;
}