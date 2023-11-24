#include<stdio.h>
#include<stdlib.h>

typedef struct listNode
{
    int data;
    struct listNode *ptrdiff;
} Nodal;

void insertBegin(Nodal **head);
void print(Nodal *head);
int count(Nodal *head);