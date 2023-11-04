
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

