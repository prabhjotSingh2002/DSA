#include<stdio.h>
#include<stdlib.h>

typedef struct student{
    int roll;
    char name[30];
    float per;
    struct student *next;
} Student;

void stud_add(Student **ptr);
void stud_show(Student *ptr);
void stud_save(Student *ptr);