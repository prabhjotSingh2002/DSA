# include "header.h"

void main()
{
    int op;
    DLL *head=0;
    while(1)
    {        
        printf("1)insert at begin\n 2)insert at end\n");
        printf("3)insert at middle\n4)print\n");
        printf("5)count\n6)delete at begin\n");
        printf("7)delete at end\n8)delete at mid\n");
        printf("9)delete all\n");
        printf("ENTER: ");
        scanf("%d",&op);

        switch(op)
        {
            case 1:insertBegin(&head);
                    break;
            case 2:insertEnd(&head);
                    break;
            case 3:insertMid(&head);
                    break;
            case 4:print(head);
                    break;
            case 5:printf("Count:%d\n",count(head));
                    break;
            case 6:deleteBegin(&head);
                    break;
            case 7:deleteEnd(&head);
                    break;
            case 8:deleteMid(&head);
                    break;
        }

    }

}

void insertBegin(DLL **hptr)
{
    DLL *new=calloc(1,sizeof(DLL));
    printf("Enter data: ");
    scanf("%d",&new->data);

    if(*hptr==0)
    {
        *hptr=new;
        return;
    }

    new->next=*hptr;
    (*hptr)->prev=new;
    *hptr=new;
}

int count(DLL *head)
{
    DLL *ptr=head;
    if(head==0)
    {
        return 0;
    }
    int c=0;
    while(ptr)
    {
        c++;
       ptr= ptr->next;
    }
    return c;
}

void insertEnd(DLL **hptr)
{
    DLL *new=calloc(1,sizeof(DLL));
    printf("Enter data: ");
    scanf("%d",&new->data);

    if(*hptr==0)
    {
        *hptr=new;
        return;
    }
    DLL *ptr=*hptr;
    while(ptr->next)
    {
        ptr=ptr->next;
    }
    new->next=ptr->next;
    new->prev=ptr;
    ptr->next=new; 
}


void insertMid(DLL **head)
{
    print(*head);

    DLL *new=calloc(1,sizeof(DLL));
    printf("Enter data: ");
    scanf("%d",&new->data);

    int pos;
    printf("Enter the position of insertion: ");
    scanf("%d",&pos);

    if(pos>count(*head)+1 )
    {
        printf("NOT VALID POSITION\n");
        return;
    }

    if(pos==1)
    {
        if(*head==0)
        {
            *head=new;
            return;
        }

        new->next=*head;
        (*head)->prev=new;
        *head=new;
        return;
    }

    DLL *ptr=*head;
    int c=1;
    while(c<pos-1 && ptr->next )
    {
            ptr=ptr->next;
            c++;
    }

    if(ptr->next==0)
    {
        new->prev=ptr;
        ptr->next=new;
    }
    else
    {
        new->next=ptr->next;
        new->prev=ptr;
        ptr->next->prev=new;
        ptr->next=new;
    }
}

void print(DLL *head)
{
    if(head==0)
    {
        printf("EMPTY LIST\n");
    }
    DLL *ptr=head;
    int c=1;
    while(ptr)
    {
        printf("DATA %d :%d \n",c++,ptr->data);
        ptr=ptr->next;
    }

}

void deleteBegin(DLL **head)
{
    if(*head==0)
    {
        printf("EMPTY RECORD\n");
        return;
    }

    if((*head)->next==0)
    {
        free(*head);
        *head=0;
        return;
    }

    *head=(*head)->next;
    (*head)->prev->next=0;
    free((*head)->prev);
    (*head)->prev=0;

}

void deleteEnd(DLL **head)
{
    if(*head==0)
    {
        printf("EMPTY RECORD\n");
        return;
    }

    if((*head)->next==0)
    {
        free(*head);
        *head=0;
        return;
    }

    DLL *ptr=*head;
    while(ptr->next)
    {
        ptr=ptr->next;
    }

    ptr->prev->next=0;
    free(ptr);
    ptr=0;

}

void deleteMid(DLL **head)
{
    if(*head==0)
    {
        printf("EMPTY RECORD\n");
        return;
    }

    print(*head);


    int pos;
    printf("ENTER POS: ");
    scanf("%d",&pos);

    if(pos>count(*head))
    {
        printf("INVALID POSITION\n");
        return;
    }
    DLL *ptr=*head;
    if(pos==1)
    {
        *head=(*head)->next;
        if(*head!=0)
            (*head)->prev=0;
        free(ptr);
        return;
    }

    int c=1;
    while(c<pos && ptr->next)
    {
        ptr=ptr->next;
        c++;
    }
    
    printf("ptr->data: %d prev->data=%d\n next->data=%d \n",ptr->data,ptr->prev->data,ptr->next->data);
    
    if(ptr->next==0)
    {
        ptr->prev->next=0;
        free(ptr);
        return;
    }
    else
    {
        ptr->prev->next=ptr->next;
        ptr->next->prev=ptr->prev;
        free(ptr);
    }
}