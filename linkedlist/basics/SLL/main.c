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
            case 16:exit(0);
            default:printf("\033[31;4;40;1m unknown choices \033[0m\n");
            
        }
    }
}

void add_begin(SLL **ptr)
{
    SLL *new=malloc(sizeof(SLL));//create a node
    printf("enter rollno name & marks \n");
    scanf("%d %s %f",&new->rollno,new->name,&new->marks);

    new->next=*ptr;//update newly created node next address

    *ptr=new;//update headptr
}

void print_node(SLL* ptr)
{
    if(ptr==0)
    {
        printf("\033[34m no record present \033[0m\n");
        return;
    }
    while(ptr)
    {
        printf("\033[35m%d %s %f \n",ptr->rollno,ptr->name,ptr->marks);//printing
        ptr=ptr->next;//visit nextnode
    }
    printf("\033[0m");
}

int count_node(SLL *ptr)
{
    if(ptr==0)
    {
        return 0;
    }
    int c=0;
    while(ptr)
    {
        c++;
        ptr=ptr->next;
    }
    return c;
}

void addEnd(SLL **ptr)
{
    SLL *new=malloc(sizeof(SLL));//create a node
    SLL *last;
    printf("enter roll name & marks\n");
    scanf(" %d %s %f",&new->rollno,new->name,&new->marks);

    new->next=0;

    if(*ptr==0)
        *ptr=new;
    else
    {
        last =*ptr;
        while(last->next)
        {
            last=last->next;
        }
        last->next=new;
    }
        
}

void saveFile(SLL *ptr)
{
    if(ptr==0)
    {
            printf("\033[34 no record present \033[0m \n");
            return;   
    }
    FILE *fp=fopen("std.txt","w");
    
    while(ptr)
    {
        fprintf(fp,"%d %s %f \n",ptr->rollno,ptr->name,ptr->marks);
        ptr=ptr->next;
    }
    printf("data saved in file \n");
    fclose(fp);
}

void readFile(SLL **ptr)
{
    FILE *fp=fopen("std.txt","r");
    if(fp==0)
    {
        printf("file is not present\n");
        return;
    }
    SLL *last,*new;

    while(1)
    {
        new =malloc(sizeof(SLL));//create a node
        if(fscanf(fp,"%d%s%f",&new->rollno,new->name,&new->marks)==-1)
             break;
            //read data one by one from file 

        new->next=0;

        if(*ptr==0) //if no record update head ptr
             *ptr=new;
        else
        {
            //if record present
            last=*ptr;
            while(last->next)//finding last node
                    last=last->next;

            last->next=new;//update last node next address
        }
    }

}

void addMiddle(SLL **ptr)
{
    SLL *new=malloc(sizeof(SLL));//create a node
    SLL *des;
    printf("enter roll ,name & marks\n");
    scanf("%d %s %f",&new->rollno,new->name,&new->marks);

    //update head ptr

    if((*ptr==0) || (new->rollno < (*ptr)->rollno ) )
    {
        new->next=*ptr;
        *ptr=new;
    }
    else
    {
        des=*ptr;//always holding first node address

        while((des->next!=0) && (new->rollno > des->next->rollno ) )
                des=des->next;//moving des to a desired pos

        new->next=des->next;
        des->next=new;
    }
}