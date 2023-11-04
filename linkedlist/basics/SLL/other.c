void reverse_link(SLL **ptr)
{
    if(*ptr==0)
    {
        printf("NO RECORD FOUND\n");
        return;
    }
    int c=count_node(*ptr);//finding count

    SLL **arr,*temp=*ptr;
    arr=malloc(sizeof(SLL*)*c);

    int i=0;
//Storing address in array

    while(temp)
    {
        arr[i++]=temp;
        temp=temp->next;
    }

//modify link position

    for(i=1;i<c;i++)
    {
        arr[i]->next=arr[i-1];
    }    

    arr[0]->next=0;
    *ptr=arr[c-1];
}

void sort_data(SLL * ptr)
{
    if(ptr)
    {
        printf("NO RECORD FOUND\n");
        return;
    }
    SLL *p1=ptr,*p2,temp;
    int i,j,c=count_node(ptr);//finding count

    for(i=0;i<c-1;i++)
    {
        p2=p1->next;
        for(j=0;j<c-1-i;j++)
        {
            if(p1->rollno>p2->rollno)
            {
                temp.rollno=p1->rollno;
                strcpy(temp.name,p1->name);
                temp.marks=p1->marks;

                p->rollno=p2->rollno;
                strcpy(p1->name,p2->name);
                p->marks=p2->marks;

                p2->rollno=temp.rollno;
                strcpy(p2->name,temp.name);
                p2->marks=temp.marks;
            }
            p2=p2->next;
        }
        p1=p1->next;
    }
}

void search_node(SLL *ptr)
{
    if(ptr==0)
    {
        printf("NO RECORDS FOUND\n");
        return;
    }
    int num;
    printf("enter roll no. to search\n");
    scanf("%d",&num);
    while(ptr)
    {
        if(num==ptr->rollno)
        {
            printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks); 
            return;
        }
        ptr=ptr->next;//moving ptr
    }
    printf("roll no. not found\n");
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
