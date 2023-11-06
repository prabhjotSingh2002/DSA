#include "header.h"

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