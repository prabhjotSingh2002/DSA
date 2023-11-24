# include "header.h"

void main()
{
    int op;
    Nodal *head=(Nodal *)NULL;
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
            // case 2:insertEnd(&head);
            //         break;
            // case 3:insertMid(&head);
            //         break;
            case 4:print(head);
                    break;
            case 5:printf("Count:%d\n",count(head));
                    break;
            // case 6:deleteBegin(&head);
            //         break;
            // case 7:deleteEnd(&head);
            //         break;
            // case 8:deleteMid(&head);
            //         break;
        }

    }

}

void insertBegin(Nodal **head)
{
    Nodal *new=calloc(1,sizeof(Nodal));
    printf("Enter data: ");
    scanf("%d",&new->data);

    if(*head==(Nodal *)NULL)
    {
        *head=new;
        return;
    }

    new->ptrdiff=(Nodal *)NULL^(*head);
    *head=new;

}

void print(Nodal *head)
{
    if(head==(Nodal *)NULL)
    {
        printf("Empty list\n");
        return;
    }
    Nodal *ptr=head,*prev=(Nodal *)NULL,*temp;
    int c=1;

    while(ptr)
    {
        printf("DATA %d: %d\n",c,ptr->data);
        c++;
        temp=ptr;
        ptr=prev ^ ptr->ptrdiff;
        prev=temp;
    }

}

int count (Nodal *head)
{
    if(head==(Nodal *)NULL)
    {
        printf("Empty list\n");
        return 0;
    }
    Nodal *ptr=head,*prev=(Nodal *)NULL,*temp;
    int c=0;

    while(ptr->ptrdiff ^ prev)
    {
        printf("DATA %d: %d\n",c,ptr->data);
        c++;
        temp=ptr;
        ptr=prev ^ ptr->ptrdiff;
        prev=temp;
    }
    return c;
}