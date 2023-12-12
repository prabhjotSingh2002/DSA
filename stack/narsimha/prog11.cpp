//reverse stack using recursion

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
            cout<<i++<<". DATA: "<<iter->data<<"\t";
            iter=iter->next;
        }
    }

};

void insertAtBottom(Stack &s1,int data)
{
    int temp;
    if(s1.IsEmpty())
    {
        s1.push(data);
        return;
    }
    temp=s1.pop();
    insertAtBottom(s1,data);
    s1.push(temp);
}
void reverseStack(Stack &s1)
{
    int data;
    if(s1.IsEmpty())return;
    data=s1.pop();
    reverseStack(s1);
    insertAtBottom(s1,data);

}

int main()
{
    Stack s1;
    s1.push(10);
    s1.push(11);
    s1.push(12);
    s1.push(13);

    s1.print();
    reverseStack(s1);
    s1.print();
}
