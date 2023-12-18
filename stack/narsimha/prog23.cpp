#include<iostream>
using namespace std;

class Stack
{
    typedef struct Node
    {
        int data;
        struct Node *next;
    } Node;
    
    Node *top; 

    public:
    Stack()
    {
        top=NULL;
    }
    
    void push(int data)
    {
        Node *n=new Node();
        n->data=data;
        n->next=NULL;
        if(top==NULL)
        {
            top=n;
            return;
        }
        n->next=top;
        top=n;
    }

    int pop()
    {
        if(top==NULL)
        {
            cout<<"STACK UNDERFLOW"<<endl;
            return -1;
        }
        int data1=top->data;
        Node *nextT=top->next;
        delete top;
        top=nextT;
        return data1;
    }

    int IsEmpty()
    {
        return top==NULL;
    }

    int peek()
    {
        if(top==NULL)
        {
            return -1;
        }
        return top->data;
    }

    void print()
    {
        if(top==NULL)
        {
            cout<<"STACK UNDERFLOW"<<endl;
            return;
        }
        Node *iter=top;
        int i=1;
        cout<<endl;
        while(iter)
        {
            cout<<i++<<". DATA: "<<(char)iter->data<<"\t";
            iter=iter->next;
        }
    }

};

void findingSpan(int a[],int n)
{
    Stack d;
    int p;
    int i;
    int s[n]={0};
    for(i=0;i<n;i++)
    {
        while(!d.IsEmpty())
        {
            if(a[i]>a[d.peek()])
            {
                d.pop();
            }
            else
             break;
        }
        if(d.IsEmpty())
        {
            p=-1;
        }
        else
        {
            p=d.peek();
        }
        s[i]=i-p;
        d.push(i);
    }

    for(int i=0;i<n;i++)
    {
        cout<<s[i]<<endl;
    }
}

int main()
{
    int n=5;
    int a[5]={6,3,4,5,2};
    findingSpan(a,n);
    
}