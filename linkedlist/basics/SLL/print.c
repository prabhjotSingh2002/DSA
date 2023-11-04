
void reverse_print(SLL *ptr)
{
    if(ptr==0)
    {
        printf("no record present\n");
        return;
    }

    SLL *temp;
    int i,j,c=count_node(ptr);

    for(i=0;i<c;i++)
    {
        temp=ptr;
        for(j=0;j<c-1-i;j++)
        {
            temp=temp->next;
        }
        printf("%d %s %f\n",temp->rollno,temp->name,temp->marks);
    }
}

void print_rec(SLL *ptr)
{
    if(ptr)
    {
        printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);

        if(ptr->next!=0)//check if next ptr is present then pass it
            print_rec(ptr->next); 
    }
    else
    printf("NO RECORD PRESENT\n");
}

void rev_rec(SLL *ptr)
{
    if(ptr)
    {
        
        if(ptr->next!=0)//check if next ptr is present then pass it
            rev_rec(ptr->next);
        
        printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks); 
    }
    else
    printf("NO RECORD PRESENT\n");
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
