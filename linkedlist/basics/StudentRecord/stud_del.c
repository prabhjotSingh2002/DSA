#include "header.h"

void delete_all(Student **ptr)
{
    if(*ptr==0)
    {
        printf("NO RECORD PRESENT\n");
        return;
    }
    int c=1;
    Student * del=*ptr;//holding first node address
    while(del)
    {
        *ptr=del->next;
        printf("\033[34m node %d deleted \n\033[0m",c++);
        sleep(1);
        free(del);
        del=*ptr;
    }
    printf("all records are deleted\n");
}

void del_stud(Student **ptr)
{
    if(*ptr==0)
    {
        printf("no record found\n");
        return;
    }
    
    int op;
    printf("Enter op by which to del:\n 1)by name\n2)by rollno \n");
    scanf("%d",&op);
    if(op==1)
    {
        char name[20];
        printf("Name: ");
        scanf(" %s",name);

        Student *del=*ptr,*prev=0;//holding first node address

        while(del)
         {
            if(strcmp(del->name,name)==0)//if name found
            {
                if(del==*ptr)//if its first node
                {
                    *ptr=del->next;//update headptr
                }
                else
                {
                    prev->next=del->next;//update prev
                }
                free(del);
                return;
            }
            prev=del;//follow del one step behind
            del=del->next;//to visit next node
         }
        printf("No Name Found\n");//name not found
    }
    else if(op==2)
    {
        int roll;
        printf("Roll: ");
        scanf(" %d",&roll);

        Student *del=*ptr,*prev=0;//holding first node address

        while(del)
         {
            if(del->roll==roll)//if name found
            {
                if(del==*ptr)//if its first node
                {
                    *ptr=del->next;//update headptr
                }
                else
                {
                    prev->next=del->next;//update prev
                }
                free(del);
                return;
            }
            prev=del;//follow del one step behind
            del=del->next;//to visit next node
         }
        printf("No Roll Found\n");//name not found
    }
    else
    {
        printf("NOT VALID OP\n");
    }
    
}