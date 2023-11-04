#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

typedef struct student{

    int roll;
    char name[20];
    float marks;
    struct student *next;
} CSLL;

void add_begin(CSLL **);
void print_node(CSLL *);
int count_node(CSLL *);
void add_end(CSLL **);
void delete_pos(CSLL **);
