/*
Problem-38 Split a Circular Linked List into two equal parts. If the number of nodes in the
list are odd then make first list one node extra than second list.

Algorithm
• Store the mid and last pointers of the circular linked list using Floyd cycle finding
algorithm.
• Make the second half circular.
• Make the first half circular.
• Set head pointers of the two linked lists.

*/

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

typedef struct student{
    int roll;
    struct student *next;
} CSLL;

void add_begin(CSLL **);
void print_node(CSLL *);
int count_node(CSLL *);
void add_end(CSLL **);
void delete_pos(CSLL **);

void splitList(CSLL *head,CSLL **head1,CSLL **head2);

int main()
{
    int op,c;
    CSLL *headptr=0,*head1=0,*head2=0;

    while(1)
    {
        printf("\033[32m enter your choice \n");
        printf("1)add_begin 2)add_end 3)print_node 4)count_node 5)delete_pos 6)exit 7)splitList\033[0m\n");

        scanf("%d",&op);

        switch(op)
        {
            case 1:add_begin(&headptr);break;
            case 2:add_end(&headptr);break;
            case 3:print_node(headptr);break;
            case 4:c=count_node(headptr);
                    printf("total count: %d \n",c);
                    break;
            case 5:delete_pos(&headptr);break;
            case 6:exit(0);break;
            case 7:splitList(headptr,&head1,&head2);
                    printf("1ST CSLL\n");
                    print_node(head1);
                    printf("2nd CSLL\n");
                    print_node(head2);
                    break;
            default:printf("\033[31;4;40;m unkown choice \033[0m \n");
        }

    }
}



void add_begin(CSLL **ptr)
{
    CSLL *new,*last;
    new=malloc(sizeof(CSLL));
    printf("enter rollno \n");
    
    scanf("%d",&new->roll);

    if(*ptr==0)
        new->next=new;
    else
    {
        new->next=*ptr;
        last=*ptr;//holding first node address
        while(last->next!=*ptr)
            last=last->next;

        last->next=new;
    }
    *ptr=new;
}


void add_end(CSLL **ptr)
{
    CSLL *new,*last;
    new = malloc(sizeof(CSLL));
    printf("enter rollno\n");

    scanf("%d",&new->roll);

    if(*ptr==0)
    {
        new->next=new;
        *ptr=new;
    }
    else
    {
        new->next=*ptr;
        last=*ptr;//holding first node addr
        while(last->next!=*ptr)
            last=last->next;

        last->next=new;
    }

}

void print_node(CSLL *ptr)
{
    if(ptr==0)
    {
        printf("no record found\n");
        return;
    }
    CSLL *head=ptr;
    while(ptr)
    {
        printf("%d \n",ptr->roll);
        ptr=ptr->next;
        if(ptr==head)
            break;
    }
}

int count_node(CSLL *ptr)
{
    if(ptr==0)
        return 0;
    
    int c=0;
    CSLL *head=ptr;
    while(ptr)
    {
        c++;
        ptr=ptr->next;
        if(ptr==head)
            break;
    }
    return c;
}

void delete_pos(CSLL** ptr)
{
    if(*ptr==0)
    {
        printf("No record found\n");
        return;
    }
    int i,pos,c=count_node(*ptr);//finding node count
    CSLL *del=*ptr,*prev ,*last;

    printf("enter the pos\n");
    scanf("%d ",&pos);

    if(pos>=1 && pos<=c) //if pos is in range
    {
        for(i=1;i<=c;i++)
        {
            if(pos==i)//find exact pos
            {
                if(pos==1)//if it is first pos
                {
                    last=*ptr;//holding first node address
                    
                    //to find last node
                    while(last->next!=*ptr)
                        last=last->next;

                    //if node count is more than 1
                    if(c!=1)
                    {
                        last->next=del->next;
                        *ptr=del->next;
                    }
                    else //if node count is 1
                        *ptr=0;
                    
                }
                else
                {
                    //for middle &last node
                    prev->next=del->next;//update previous node
                }
            }
            prev=del;//follow previous of del
            del=del->next;
        }
    }
    else
        printf("Node position out of range\n");
}

void splitList(CSLL *head,CSLL **head1,CSLL **head2)
{
    CSLL *ptr1=0,*ptr2=0;
    ptr1=ptr2=head;

    int i=0;

    while(ptr1->next!=head)
    {
        if(i==0)
        {
            ptr1=ptr1->next;
            i=1;
        }
        else if(i==1)
        {
            ptr1=ptr1->next;
            ptr2=ptr2->next;
            i=0;
        }
        printf("ptr1: %d ptr2:%d\n",ptr1->roll,ptr2->roll);
    }



    *head1=head;
    *head2=ptr2->next;

    ptr2->next=*head1;
    ptr1->next=*head2;
}