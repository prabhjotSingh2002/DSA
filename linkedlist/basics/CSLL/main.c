#include "header.h"

int main()
{
    int op,c;
    CSLL *headptr=0;
    while(1)
    {
        printf("\033[32m enter your choice \n");
        printf("1)add_begin 2)add_end 3)print_node 4)count_node 5)delete_pos 6)exit \035[0m\n");

        scanf("%d",&op);

        switch(op)
        {
            case 1:add_begin(&headptr);break;
            case 2:add_end(&headptr);break;
            case 3:print_node(headptr);break;
            case 4:c=count_node(headptr);
                    printf("total count: %d \n",c);
                    break;
            case 5:delete_pos(&headptr);break;
            case 6:exit(0);
            default:printf("\033[31;4;40;m unkown choice \033[0m \n");
        }

    }
}



void add_begin(CSLL **ptr)
{
    CSLL *new,*last;
    new=malloc(sizeof(CSLL));
    printf("enter rollno ,name & marks\n");
    
    scanf("%d %s %f",&new->roll,new->name,&new->marks);

    if(*ptr==0)
        new->next=new;
    else
    {
        new->next=*ptr;
        last=*ptr;//holding first node address
        while(last->next!=*ptr)
            last=last->next;

        last->next=new;
    }
    *ptr=new;
}


void add_end(CSLL **ptr)
{
    CSLL *new,*last;
    new = malloc(sizeof(CSLL));
    printf("enter rollno, name & marks \n");

    scanf("%d %s %f",&new->roll,new->name,&new->marks);

    if(*ptr==0)
    {
        new->next=new;
        *ptr=new;
    }
    else
    {
        new->next=*ptr;
        last=*ptr;//holding first node addr
        while(last->next!=*ptr)
            last=last->next;

        last->next=new;
    }

}

void print_node(CSLL *ptr)
{
    if(ptr==0)
    {
        printf("no record found\n");
        return;
    }
    CSLL *head=ptr;
    while(ptr)
    {
        printf("%d %s %f\n",ptr->roll,ptr->name,ptr->marks);
        ptr=ptr->next;
        if(ptr==head)
            break;
    }
}

int count_node(CSLL *ptr)
{
    if(ptr==0)
        return 0;
    
    int c=0;
    CSLL *head=ptr;
    while(ptr)
    {
        c++;
        ptr=ptr->next;
        if(ptr==head)
            break;
    }
    return c;
}

void delete_pos(CSLL** ptr)
{
    if(*ptr==0)
    {
        printf("No record found\n");
        return;
    }
    int i,pos,c=count_node(*ptr);//finding node count
    CSLL *del=*ptr,*prev ,*last;

    printf("enter the pos\n");
    scanf("%d ",&pos);

    if(pos>=1 && pos<=c) //if pos is in range
    {
        for(i=1;i<=c;i++)
        {
            if(pos==i)//find exact pos
            {
                if(pos==1)//if it is first pos
                {
                    last=*ptr;//holding first node address
                    
                    //to find last node
                    while(last->next!=*ptr)
                        last=last->next;

                    //if node count is more than 1
                    if(c!=1)
                    {
                        last->next=del->next;
                        *ptr=del->next;
                    }
                    else //if node count is 1
                        *ptr=0;
                    
                }
                else
                {
                    //for middle &last node
                    prev->next=del->next;//update previous node
                }
            }
            prev=del;//follow previous of del
            del=del->next;
        }
    }
    else
        printf("Node position out of range\n");
}
