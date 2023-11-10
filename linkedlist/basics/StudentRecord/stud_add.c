#include "header.h"

void stud_add(Student **ptr)
{      
    system("cls");
    Student *new =malloc(sizeof(Student));
    printf("enter student name and marks\n");
    scanf("%s %f",new->name,&new->per);
    

    if((*ptr==0)||((*ptr)->roll)>1)
    {
        new->roll=1;
        new->next=(*ptr);
        *ptr=new;//updating head ptr
    }
    else
    {
        Student *curr,*prev;
        curr=*ptr;
        prev=*ptr;
        int flag=0;

        while(curr->next)
        {
            if(prev->roll+1<curr->roll)
            {
                flag=1;
                break;
            }
            prev=curr;
            curr=curr->next;
        }

        if(flag==1)
        {
            new->roll=prev->roll+1;
            new->next=curr;
            prev->next=new;
        }
        else
        {
            new->roll=curr->roll+1;
            new->next=curr->next;
            curr->next=new;
        }
    }
    sleep(1);
}