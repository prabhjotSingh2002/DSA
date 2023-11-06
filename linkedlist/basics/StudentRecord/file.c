#include "header.h"

void stud_save(Student *ptr)
{
    FILE *fp=fopen("student.dat","w");
    if(fp==0)
    {
        printf("File is not opening\n");
        return;
    }
    if(ptr==0)
    {
        printf("No Data Record present\n");
        return;
    }

    Student *last=ptr;

    while(last!=0)
    {
        fprintf(fp,"%d %s %f \n",last->roll,last->name,last->per);
        last=last->next;
    }
    printf("your data has been successfully saved\n");
    fclose(fp);
    sleep(1);
}

void stud_read(Student **ptr)
{
    FILE *fp=fopen("student.dat","r");
    if(fp==0)
    {
        printf("File is not opening\n");
        return;
    }

     Student *new,*last;

    while(1)
    {
        new=malloc(sizeof(Student));
        if((fscanf(fp,"%d %s %f",&new->roll,new->name,&new->per)==-1))
                    break;
        
        new->next=0;

        if(*ptr==0)
        {
            *ptr=new;
        }
        else
        {
            last=*ptr;

            while(last->next)
            {
                last=last->next;
            }
            last->next=new;

        }
    }
    fclose(fp);
}