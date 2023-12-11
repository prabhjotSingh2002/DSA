#include<stdio.h>
#include<stdlib.h>
#define INT_MIN -32345

typedef struct DynArrayStack
{
    int top,capacity,*array;
}DAS;

DAS *createStack()
{
    DAS *s=malloc(sizeof(DAS));
    if(!s) return NULL;
    s->capacity=1;
    s->top=-1;
    //allocate an array of size 1 initially
    s->array=malloc(s->capacity * sizeof(int));
    if(!s->array) return NULL;
    return s;
}

int IsFullStack(DAS *s)
{
    return (s->top==s->capacity-1);
}

void DoubleStack(DAS *s)
{
    s->capacity*=2;
    s->array=realloc(s->array,s->capacity);
}

void push(DAS *s,int x)
{
    //No overflow in this implementation
    if(IsFullStack(s))
            DoubleStack(s);
    s->array[++(s->top)]=x;
}

int IsEmptyStack(DAS *s)
{
    return s->top==-1;
}

int Top(DAS *s)
{
    if(IsEmptyStack(s))
        return INT_MIN;
    return s->array[s->top];
}

int Pop(DAS *s)
{
    if(IsEmptyStack(s))
        return INT_MIN;
    return s->array[(s->top)--];
}

void DeleteStack(DAS *s)
{
    if(s)
    {
        if(s->top>-1) free(s->array);
        free(s);
    }
}

void main()
{
    int op,data;
    DAS *p=createStack();
    while(1)
    {
        printf("1.PUSH\n2.POP\n3.TOP\n4.DeleteStack\n5.EXIT\n");
        printf("ENTER : ");
        scanf("%d",&op);

        switch(op)
        {
            case 1:printf("ENTER DATA\n");
                    scanf("%d",&data);
                    push(p,data);
                    break;
            case 2:printf("%d has popped\n",Pop(p));
                    break;
            case 3:printf("TOP element:%d\n",Top(p));
                    break;
            case 4:DeleteStack(p);
                    printf("STACK HAVE BEEN DELETED\n");
                    break;
            case 5:return;
            default:printf("YOU HAVE ENTERD WRONG OPTION\n");
        }
    }
}