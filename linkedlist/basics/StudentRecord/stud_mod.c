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
    
    Student **arr[20];
    int idx=0;

    char op;
    scanf(" %c",&op);

    if(op>='A' && op<='Z')
    {
        op=op^32;
    }

    if(op=='r')
    {
        idx=0;
        int roll;
        printf("Enter roll no.\n");
        scanf("%d",&roll);

        while(ptr)
        {
            if(ptr->roll==roll)
            {
                flag=1;
                idx++;
                //arr=realloc(arr,sizeof(Student**)*idx);
                arr[idx-1]=&ptr;
                //ptr=makeChange(ptr);
            }
            ptr=ptr->next;//moving ptr
        }
        if(flag==0)
            printf("Roll No. not found\n");

   //     recordRecieved(arr,idx);
    }
    else if(op=='n')
    {
        idx=0;
        char name[40];
        printf("Enter name\n");
        scanf(" %s",name);

        while(ptr)
        {
            if(strcmp(ptr->name,name)==0)
            {
                // flag=1;
                // ptr=makeChange(ptr);

                flag=1;
                idx++;
               // arr=realloc(arr,sizeof(Student**)*idx);
                arr[idx-1]=&ptr;
            }
            ptr=ptr->next;//moving ptr
        }
        if(flag==0)
            printf("Name not found\n");

     //   recordRecieved(arr,idx);
    }
    else if(op=='p')
    {
        idx=0;
        float per;
        printf("Enter percentage\n");
        scanf("%f",&per);

        while(ptr)
        {
            if(ptr->per==per)
            {
                // flag=1;
                //  ptr=makeChange(ptr);

                flag=1;
                idx++;
                //arr=realloc(arr,sizeof(Student**)*idx);
                arr[idx-1]=&ptr;
            }
            ptr=ptr->next;//moving ptr
        }
        if(flag==0)
         printf("Percentage not found\n");

       // recordRecieved(arr,idx);
    }
    else 
    {
        printf("INVALID OPTION\n");        
    }
    //printf("hi......%d %d\n",idx,(*(arr[0]))->roll);
    int i;
   /* for(i=0;i<idx;i++)
    {
             printf("RECORD ENCOUNTERD:%d %s  %f \n",(*arr[i])->roll,(*arr[i])->name,(*arr[i])->per);
    }*/
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

void recordRecieved(Student ***arr,int idx)
{
        if(idx==0)
        {
            return;
        }
        int i=0;
        for(i=0;i<idx;i++)
        {
             printf("RECORD ENCOUNTERD:%d %s  %f \n",(*arr[i])->roll,(*arr[i])->name,(*arr[i])->per);
        }
        if(1<idx)
        {
            int roll;
            printf("Enter the roll no. to pick among these--> ");
            scanf("%d",&roll);
            for(i=0;i<idx;i++)
            {
                if(((*arr[i])->roll)==roll)
                {
                    
                    printf("ENTER THE CHANGES YOU WANT TO CHANGE\n");
                    printf("NAME: ");
                    scanf("%s",(*arr[i])->name);
                    printf("PERCENTAGE: ");
                    scanf("%f",&((*arr[i])->per));

                    return;  
                }
            }
            printf("You haven't given correct roll number\n");
        }
        else
        {
             printf("ENTER THE CHANGES YOU WANT TO CHANGE\n");
             printf("NAME: ");
             scanf("%s",(*arr[i])->name);
             printf("PERCENTAGE: ");
             scanf("%f",&((*arr[i])->per));   
        }
}