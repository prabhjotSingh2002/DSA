#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

int queue[SIZE];

int top=-1;
void enqueue();
void dequeue();
void display();

void main()
{
    int op;
    while(1)
    {
        printf("1.To enqueue\n2.To dequeue\n3.To display\n4.To clear\nEnter op: ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:enqueue();break;
            case 2:dequeue();break;
            case 3:display();break;
            case 4:system("cls");break;
            default:printf("NOT VALID OPTION\n");
        }
    }
}

void enqueue()
{
    if(top>=SIZE-1)
    {
        printf("queue is overflowed\n");
        return;
    }
    top++;
    printf("enter data: ");
    scanf("%d",&queue[top]);
}

void dequeue()
{
    if(top<0)
    {
        printf("stack is underflow\n");
        return;
    }
    int i;
    printf("data: %d is deleted\n",queue[0]);
    for(i=0;i<top;i++)
    {
        queue[i]=queue[i+1];
    }
    
    top--;
   
}

void display()
{
    if(top<0)
    {
        printf("queue is underflow\n");
        return;
    }

    int i;
    for(i=0;i<=top;i++)
    {
        printf("data: %d\n",queue[i]);
    }
}