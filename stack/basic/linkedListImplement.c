#include<stdio.h>
#include<stdlib.h>

typedef struct listNode{
    int data;
    struct listNode *next;
} Node;

Node stack *createStack()
{
    return NULL;
}

void push(Node**top,int data)
{
    Node *temp=malloc(sizeof(Node));
    if(!temp) return NULL;
    temp->data=data;
    temp->next=*top;
    *top=temp;
}

int IsEmptyStack(Node *temp)
{
    return top==NULL;
}

int pop(Node**top)
{
    int data;
    Node *temp;
    if(IsEmptyStack(top))
            return INT_MIN;
    temp=*top;
    *top=(*top)->next;
    data=temp->data;
    free(temp);
    return data;
}
int Top(Node *top)
{
    if(IsEmptyStack(top)) return INT_MIN;
    return top->next->data;
}

void deleteStack(Node**top)
{
    Node *temp,*p;
    p=*top;
    while(p->next)
    {
        temp=p->next;
        p->next=temp->next;
        free(temp);
    }
    free(p);
}