#include "header.h"

void main()
{
    Student *headptr=0;
    init(&headptr);
    while(1)
    {
        system("cls");
        printf("\033[4m ***** STUDENT RECORD MENU*****\033[0m\n\n");
        printf("a/A : add new record\n");
        printf("d/D : delete a record\n");
        printf("s/S : show the list\n");            
        printf("m/M : modify a record\n");
        printf("v/V : save\n");
        printf("e/E : exit\n");
        printf("t/T : sort the list\n");
        printf("l/L : delete all the records\n");
        printf("r/R : reverse the list\n\n");
        
        char op;
        printf("Enter your choice: ");
        scanf(" %c",&op);

        if(op>='A' && op<='Z')
                op^=32;
        
        switch(op)
        {
            case 'a': stud_add(&headptr);
                    break;
            // case d: printf("d/D : delete a record\n");
            //         break;
            case 's': stud_show(headptr);
                    break;
            // case m: printf("m/M : modify a record\n");
            //         break;
            case 'v': stud_save(headptr);
                    break;
            case 'e':end_prog(headptr);
                    break;
            case 't': stud_sort(headptr);
                    break;
            case 'l':delete_all(&headptr);
                    break;
            // case r: printf("r/R : reverse the list\n");
            //         break;
            default:printf("invalid choice\n");
                    break;
        }
        sleep(5);
    }
}

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

void stud_show(Student *ptr)
{
    system("cls");
    if(ptr==0)
    {
        printf("No student Record\n");
        return;
    }
    Student *last=ptr;
    printf("    Roll    |   Name   |  Percentage \n");

    while(last!=0)
    {
        printf("  %d   |  %s    |  %f    \n",last->roll,last->name,last->per);
        last=last->next;
    }
    sleep(2);
}

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

void end_prog(Student *ptr)
{
    system("cls");
    char ch;
    printf("Enter\nS/s:save and exit\nE/e:exit without saving\n");
    scanf(" %c",&ch);

    if(ch=='s')
    {
        stud_save(ptr);
        exit(0);
    }
    else if(ch=='e')
    {
        exit(0);
    }
}

void stud_sort(Student *ptr)
{
    system("cls");
    if(ptr==0)
    {
        printf("No Data Records Present\n");
        return;
    }
    Student *ptr2,*ptr1=ptr;
    int i,j,c=record_count(ptr);

    char op;

    printf("N/n: sort with name\nP/p:sort with percentage \nENTER: ");
    scanf(" %c",&op);

    if(op>='A' && op<='Z')
    {
        op=op^32;
    }

    if((op!='n') &&(op!='p'))
    {
        printf("INVALID OPTION\n");
        return;
    }

    for(i=0;i<c;i++)
    {
        ptr2=ptr1;
        for(j=i+1;j<=c;j++)
        {
            ptr2=ptr2->next;
            if((op=='n')&&(strcmp(ptr1->name,ptr2->name)>0))
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
            else if((op=='p')&&(ptr1->per>ptr2->per))
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
        }
        ptr1=ptr1->next;
    }
}

int record_count(Student *ptr)
{
    if(ptr==0)
    {
        return 0;
    }
    int c=0;
    while(ptr->next)
    {
       c++;
       ptr=ptr->next;
    }
    return c;
}

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
}

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