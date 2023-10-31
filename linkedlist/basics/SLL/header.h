#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

typedef struct Student
{
    int rollno;
    char name[20];
    float marks;
    struct Student * next;
} SLL;

void add_begin(SLL**);
void print_node(SLL *);
int count_node(SLL *);
void saveFile(SLL *);
void addEnd(SLL **);
void readFile(SLL **);
void addMiddle(SLL **);