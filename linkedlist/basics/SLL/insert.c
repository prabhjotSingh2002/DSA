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





void add_begin(SLL **ptr)
{
    SLL *new=malloc(sizeof(SLL));//create a node
    printf("enter rollno name & marks \n");
    scanf("%d %s %f",&new->rollno,new->name,&new->marks);

    new->next=*ptr;//update newly created node next address

    *ptr=new;//update headptr
}
