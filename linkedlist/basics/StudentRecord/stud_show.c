#include "header.h"

void stud_show(Student *ptr)
{
    system("cls");
    if(ptr==0)
    {
        printf("No student Record\n");
        return;
    }
    Student *last=ptr;
    printf("    Roll   |          Name             |  Percentage \n");
    printf("-----------------------------------------------------\n");
    while(last!=0)
    {
        printf("    %3d    |   %21s   |  %10f \n",last->roll,last->name,last->per);
        last=last->next;
    }
    sleep(2);
}
int record_count(Student *ptr)
{
    if(ptr==0)
    {
        return 0;
    }
    int c=0;
    while(ptr)
    {
       c++;
       ptr=ptr->next;
    }
    return c;
}
