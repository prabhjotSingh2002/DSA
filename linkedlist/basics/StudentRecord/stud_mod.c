#include "header.h"

void stud_mod(Student *ptr)
{
    if(ptr==0)
    {
        printf("NO RECORD PRESENT\n");
        return;
    }

    int flag=0;

    printf("Enter which record to search for modification\nR/r:to search a roll no\nN/n:to search a name\nP/p:percentage based\n");
    
    char op;
    scanf(" %c",&op);

    if(op>='A' && op<='Z')
    {
        op=op^32;
    }

    if(op=='r')
    {
        int roll;
        printf("Enter roll no.\n");
        scanf("%d",&roll);

        while(ptr)
        {
            if(ptr->roll==roll)
            {
                flag=1;
                ptr=makeChange(ptr);
            }
            ptr=ptr->next;//moving ptr
        }
        if(flag==0)
            printf("Roll No. not found\n");
    }
    else if(op=='n')
    {
        char name[40];
        printf("Enter name\n");
        scanf(" %s",name);

        while(ptr)
        {
            if(strcmp(ptr->name,name)==0)
            {
                flag=1;
                ptr=makeChange(ptr);
            }
            ptr=ptr->next;//moving ptr
        }
        if(flag==0)
            printf("Name not found\n");
    }
    else if(op=='p')
    {
        float per;
        printf("Enter percentage\n");
        scanf("%f",&per);

        while(ptr)
        {
            if(ptr->per==per)
            {
                flag=1;
                 ptr=makeChange(ptr);
            }
            ptr=ptr->next;//moving ptr
        }
        if(flag==0)
         printf("Percentage not found\n");
    }
    else 
    {
        printf("INVALID OPTION\n");        
    }
    return;
}

 Student *makeChange(Student *ptr)
{
    printf("RECORD ENCOUNTERD:%d %s  %f \n",ptr->roll,ptr->name,ptr->per);
    printf("ENTER THE CHANGES YOU WANT TO CHANGE\n");
    printf("NAME: ");
    scanf("%s",ptr->name);
    printf("PERCENTAGE: ");
    scanf("%f",&(ptr->per));

    return ptr;
}