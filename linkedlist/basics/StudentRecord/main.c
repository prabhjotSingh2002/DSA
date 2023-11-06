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
                        sleep(1);
                        break;  
            case 'd':  stud_show(headptr);
                        del_stud(&headptr);
                        sleep(1);
                        break;
            case 's': stud_show(headptr);
                        sleep(2);
                        break;
            case 'm': stud_mod(headptr);
                        sleep(1);
                        break;
            case 'v': stud_save(headptr);
                        break;
            case 'e':end_prog(headptr);
                        break;
            case 't': stud_sort(headptr);
                        sleep(1);
                        stud_show(headptr);
                        break;
            case 'l':delete_all(&headptr);
                        stud_show(headptr);
                        break;
            case 'r':reverse_links(&headptr);
                        stud_show(headptr);
                     break;
            default: printf("invalid choice\n");
                     break;
        }
    }
}