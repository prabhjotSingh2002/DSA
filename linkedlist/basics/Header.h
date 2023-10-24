#include<stdio.h>
#include<stdlib.h>

//declaring listnode
struct listnode
{
    int data;
    struct listnode *next;
};

//declaring DLL
struct DLLNode
{
    int data;
    struct DLLNode* next;
    struct DLLNode* prev;
};

