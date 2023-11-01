#include "header.h"

void main()
{
    Student *headptr=0;
    while(1)
    {
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
            case 'e': exit(0);
                    break;
            // case t: printf("t/T : sort the list\n");
            //         break;
            // case l: printf("l/L : delete all the records\n");
            //         break;
            // case r: printf("r/R : reverse the list\n");
            //         break;
            default:printf("invalid choice\n");
                    break;
        }
    }
}

void stud_add(Student **ptr)
{
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
}

void stud_show(Student *ptr)
{
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

}