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

class Queue
{
    public:
    Stack s1;
    Stack s2;

    void enque(int data)
    {
        s1.push(data);
    }
    int dequeue()
    {
        if(!s2.IsEmpty())
        {
            return s2.pop();
        }
        else
        {
            while(!s1.IsEmpty())
            {
                s2.push(s1.pop());
            }
            return s2.pop();
        }
    }
};

int main()
{
    Queue a;
    int i,n;
    for(i=0;i<6;i++)
    {
        cin>>n;
        a.enque(n);
    }

    for(i=0;i<4;i++)
    {
        cout<<a.dequeue()<<endl;7
    }
}