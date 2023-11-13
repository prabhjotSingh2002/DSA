#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

int stack[SIZE];

int top=-1;
void push();
void pop();
void display();

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

void push()
{
    if(top>=SIZE-1)
    {
        printf("stack is overflowed\n");
        return;
    }
    top++;
    printf("enter data: ");
    scanf("%d",&stack[top]);
}

void pop()
{
    if(top<0)
    {
        printf("stack is underflow\n");
        return;
    }
    printf("data: %d is poped\n",stack[top]);
    top--;
   
}

void display()
{
    if(top<0)
    {
        printf("stack is underflow\n");
        return;
    }

    int i;
    for(i=0;i<=top;i++)
    {
        printf("data: %d\n",stack[i]);
    }
}