#include<stdio.h>
#include<stdlib.h>

typedef struct DLLNode
{
    int data;
    struct DLLNode *next,*prev;
} DLL;

void insertBegin(DLL **);
void print(DLL *head);
void insertEnd(DLL **hptr);
int count(DLL *head);
void insertMid(DLL **head);

void deleteBegin(DLL **);
void deleteEnd(DLL **);
void deleteMid(DLL **head);
