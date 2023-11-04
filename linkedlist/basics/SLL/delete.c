
void deleteNode(SLL **ptr)
{
    if(*ptr==0)
    {
        printf("no record found\n");
        return;
    }
    char name[20];
    printf("enter name to delete\n");
    scanf(" %s",name);

    SLL *del=*ptr,*prev=0;//holding first node address

    while(del)
    {
        if(strcmp(del->name,name)==0)//if name found
        {
            if(del==*ptr)//if its first node
            {
                *ptr=del->next;//update headptr
            }
            else
            {
                prev->next=del->next;//update prev
            }
            free(del);
            return;
        }
            prev=del;//follow del one step behind
            del=del->next;//to visit next node
    }
    printf("No Name Found\n");//name not found

}

void delete_all(SLL **ptr)
{
    if(*ptr==0)
    {
        printf("NO RECORD PRESENT\n");
        return;
    }
    int c=1;
    SLL * del=*ptr;//holding first node address
    while(del)
    {
        *ptr=del->next;
        printf("\033[34m node %d deleted \n\033[0m",c++);
        sleep(1);
        free(del);
        del=*ptr;
    }
    printf("all records are deleted\n");
}
