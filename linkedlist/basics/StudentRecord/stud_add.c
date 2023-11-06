#include "header.h"

void stud_add(Student **ptr)
{      
    system("cls");
    Student *new =malloc(sizeof(Student));
    printf("enter student name and marks\n");
    scanf("%s %f",new->name,&new->per);
    
    new->next=0;

    if(*ptr==0)
    {
        *ptr=new;//updating head ptr
        new->roll=1;
    }
    else
    {
        Student *last=*ptr;
        while(last->next!=0)
        {
            last=last->next;
        }
        new->roll=last->roll+1;
        last->next=new;
    }
    sleep(1);
}