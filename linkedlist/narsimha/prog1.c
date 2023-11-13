//Problem-1 Implement Stack using Linked List
#include<stdio.h>
#include<stdlib.h>

#define MAX 5

typedef struct stack{
    int data;
    struct stack *next;
} Node;

Node *head=0;
int top=-1;

void push()
{
    if(top>=MAX-1)
    {
        printf("Stack overflowed\n");
        return;
    }
    Node *new=malloc(sizeof(Node));
    printf("enter data: ");
    scanf("%d",&new->data);
    new->next=0;

    top++;

    if(head==0)
    {
        head=new;
    }
    else
    {
        Node *ptr=head;
        while(ptr->next)
            ptr=ptr->next;

        ptr->next=new;
    }
}

void pop()
{
    if(top<0)
    {
        printf("Stack is underflowed\n");
        return;
    }
    top--;
    if(head->next==0)
    {
        free(head);
        head=0;
         printf("data: %d is deleted\n",head->data);
        printf("Stack is emptied\n");
        return;
    }
    
    Node *ptr=head;
    Node *prev=0;
    while(ptr->next)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    printf("data: %d is deleted\n",ptr->data);
    free(ptr);
    prev->next=0;
}

void display()
{
    if(top<0)
    {
        printf("Stack is underflowed\n");
        return;
    }

    Node *ptr=head;
    int c=0;
    while(ptr)
    {
        printf("%d data: %d\n",++c,ptr->data);
        ptr=ptr->next;
    }

}

void main()
{
    int op;
    while(1)
    {
        printf("1.To Push\n2.To Pop\n3.To display\n4.To clear\nEnter op: ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:push();break;
            case 2:pop();break;
            case 3:display();break;
            case 4:system("cls");break;
            default:printf("NOT VALID OPTION\n");
        }
    }
}