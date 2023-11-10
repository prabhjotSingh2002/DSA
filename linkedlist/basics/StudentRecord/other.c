#include "header.h"

char *lowercase(char *s)
{
    int i=0;
    for(i=0;s[i];i++)
    {
        if(s[i]>='A' &&s[i]<='Z')
        {
            s[i]=s[i]^32;
        }
    }
    return s;
}

void init(Student **ptr)
{
    stud_read(ptr);
    stud_sort(*ptr,0);
}

void reverse_links(Student **ptr)
{
    if(*ptr==0)
    {
        printf("No Record Found\n");
        return;
    }

    int c=record_count(*ptr);

    Student **arr,*temp=*ptr;
    arr=malloc(sizeof(Student)*c);

    int i=0;

    //storing in array
    while(temp)
    {
        arr[i++]=temp;
        temp=temp->next;
    }

    //modify link pos
    for(i=1;i<c;i++)
    {
        arr[i]->next=arr[i-1];
    }
    arr[0]->next=0;
    *ptr=arr[c-1];

    return;
}