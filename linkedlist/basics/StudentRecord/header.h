#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

typedef struct student{
    int roll;
    char name[30];
    float per;
    struct student *next;
} Student;

void stud_add(Student **ptr);
void stud_show(Student *ptr);
void stud_save(Student *ptr);
void stud_read(Student **ptr);
void end_prog(Student *ptr);
void stud_sort(Student *ptr,int user);
int record_count(Student *ptr);
char *lowercase(char *s);
void init(Student **ptr);
void delete_all(Student **ptr);
void stud_mod(Student *ptr);
Student * makeChange(Student *ptr);
void del_stud(Student **ptr);
void reverse_links(Student **ptr);

void recordRecieved(Student ***arr,int idx);