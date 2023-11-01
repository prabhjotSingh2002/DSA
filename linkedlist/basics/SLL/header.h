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
void reverse_print(SLL *);
void print_rec(SLL*);
void rev_rec(SLL *);
void delete_all(SLL **);
void search_node(SLL *);