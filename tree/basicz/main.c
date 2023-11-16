#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *left;
    int data;
    struct node *right;
}Node;

void insert(Node **head,int num);
void inorder(Node *ptr);
void preorder(Node *ptr);
void postorder(Node *ptr);


int main()
{
    int op,num;
    Node *head=0;
    while(1)
    {
        printf("\n1.to insert\n2.inorder\n3.preorder\n4.postorder\n5.search node\n6.deleteNode");
        printf("\nENTER : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1: 
                    printf("ENTER NUM: ");
                    scanf("%d",&num);
                    insert(&head,num);
                    break;
            case 2:inorder(head); 
                    break;
            case 3:preorder(head); 
                    break;
            case 4:postorder(head); 
                    break;        
            default:printf("ENTER CORRECT OP\n");
        }
    }
}

void insert(Node **head,int num)
{
    if(*head==0)
    {
        *head=calloc(1,sizeof(Node));
        (*head)->data=num;
    }
    else if(num<(*head)->data)
    {
        insert(&((*head)->left),num);
    }
    else if(num>(*head)->data)
    {
        insert(&((*head)->right),num);
    }
    else
    {
        printf("DUPLICATES NOT ALLOWED\n");
    }
}

void inorder(Node *ptr)
{
    if(ptr)
    {
        inorder(ptr->left);
        printf("%d  ",ptr->data);
         inorder(ptr->right);
    }
}

void preorder(Node *ptr)
{
    if(ptr)
    {
         printf("%d  ",ptr->data);
         preorder(ptr->left);
         preorder(ptr->right);
    }
}

void postorder(Node *ptr)
{
    if(ptr)
    {
         postorder(ptr->left);
         postorder(ptr->right);
         printf("%d  ",ptr->data);
    }
}