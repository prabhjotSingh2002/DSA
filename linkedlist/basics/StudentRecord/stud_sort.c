#include "header.h"

void stud_sort(Student *ptr,int user)
{
    if(ptr==0)
    {
        printf("No Data Records Present\n");
        return;
    }
    Student *ptr1=ptr,*ptr2;
    int i,j,c=record_count(ptr);


    int op=0;
    if(user==1)
    {
        printf("1: sort with name\n2:sort with percentage \nENTER:");
        scanf("%d",&op);
        if((op!=1) &&(op!=2))
        {
             printf("INVALID OPTION\n");
             return;
        }
    }    
    
    for(i=0;i<c-1;i++)
    {
        ptr2=ptr1->next;
        for(j=i+1;j<c;j++)
        {
            if((user==1)&&(op==1)&&(strcmp(ptr1->name,ptr2->name)>0))
            {
                float temp=ptr1->per;
                ptr1->per=ptr2->per;
                ptr2->per=temp;

                char temp1[30];
                strcpy(temp1,ptr1->name);
                strcpy(ptr1->name,ptr2->name);
                strcpy(ptr2->name,temp1);

                int temp2=ptr1->roll;
                ptr1->roll=ptr2->roll;
                ptr2->roll=temp2;
            }
            else if((user==1)&&(op==2)&&(ptr1->per>ptr2->per))
            {
                float temp=ptr1->per;
                ptr1->per=ptr2->per;
                ptr2->per=temp;

                char temp1[30];
                strcpy(temp1,ptr1->name);
                strcpy(ptr1->name,ptr2->name);
                strcpy(ptr2->name,temp1);

                int temp2=ptr1->roll;
                ptr1->roll=ptr2->roll;
                ptr2->roll=temp2;
            }
            else if((user==0)&&(ptr1->roll>ptr2->roll))
            {
                float temp=ptr1->per;
                ptr1->per=ptr2->per;
                ptr2->per=temp;

                char temp1[30];
                strcpy(temp1,ptr1->name);
                strcpy(ptr1->name,ptr2->name);
                strcpy(ptr2->name,temp1);

                int temp2=ptr1->roll;
                ptr1->roll=ptr2->roll;
                ptr2->roll=temp2;
            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
}