#include "header.h"
int main()
{
    int op,c;
    SLL *headptr=0;

    while(1)
    {
        printf("\033[32m enter you choice\n");
        printf("1)add_begin 2)add_end 3)add_middle 4)print_node 5)count_node 6)save file 7)read_file 8)reverse_print 9)print_rec  10)reverse_rec 11)delete_all 12)deleteNode 13)Search_mode 14)reverse_link 15)sort_data 16)exit \033[0m\n");

        scanf("%d",&op);

        switch(op)
        {
            case 1:add_begin(&headptr);
                    break;
            case 2:addEnd(&headptr);
                    break;
            case 3:addMiddle(&headptr);
                    break;
            case 4:print_node(headptr);
                    break;
            case 5:
                    printf("total count:%d \n",count_node(headptr));
                    break;
            case 6:saveFile(headptr);
                    break;
            case 7:readFile(&headptr);
                    break;
            case 8: reverse_print(headptr);
                    break;
            case 9:print_rec(headptr);
                    break;
            case 10:rev_rec(headptr);
                    break;
            case 11:delete_all(&headptr);
                    break;
            case 13:search_node(headptr);
                    break;
            case 16:exit(0);
            default:printf("\033[31;4;40;1m unknown choices \033[0m\n");
            
        }
    }
}




