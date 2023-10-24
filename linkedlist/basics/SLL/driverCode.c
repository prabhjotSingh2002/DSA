#include "../Header.h"
#include "SLLheader.h"

void main()
{
    int op=-1;

 while(op!=0)
 {
    printf("1. to insert \n 2. to delete from given pos \n 3. length \n 4. to delete whole list\n 0. to end ");

    scanf("%d",&op);
    if(op==0)
         break;
    switch(op)
    {
        case 1: inserting();
                    break; 
        case 2:deleting();
                    break;
        case 3:length();
                    break;
        case 4:truncate();
                    break;    
        default:
                printf("enter valid op:\n");
    }
 }
}