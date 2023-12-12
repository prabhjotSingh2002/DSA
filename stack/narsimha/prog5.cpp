//designing a stack such that GetMinimum() should be O(1)

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
    Node *top1;

    public:
    Stack()
    {
        top=NULL;
        top1=NULL;
    }
    
    void push(int data)
    {
        Node *n=new Node();
        
        /////////////////////
        Node *n1=new Node();
        //////////////////

        n->data=data;
        n->next=NULL;
        
        //////////////////
        n1->next=NULL;
        ////////////////

        if(top==NULL)
        {
            top=n;
            
            /////////////////////
            n1->data=data;
            top1=n1;
            ////////////////////////


            return;
        }
       
        

        ////////////////////
        n1->data=(top1->data>data)?data:top1->data;
        n1->next=top1;
        top1=n1;
        //////////////////////////
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
        Node *nextT=top;
        delete top;
        top=nextT;
        ////////////////////
        Node *nextT1=top1->next;
        delete top1;
        top=nextT1;
        ////////////////
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

    int GetMinimum()
    {
        return top1->data;
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

    void print1()
    {
        if(top==NULL)
        {
            cout<<"STACK UNDERFLOW"<<endl;
            return;
        }
        Node *iter=top1;
        int i=1;
        cout<<endl;
        while(iter)
        {
            cout<<i++<<". DATA: "<<iter->data<<"\t";
            iter=iter->next;
        }
    }
};

int main()
{
    Stack s1;
    s1.push(5);
    s1.push(1);
    s1.push(2);
    s1.push(10);
    s1.push(-1);
    s1.push(9);
    s1.push(6);

    cout<<s1.GetMinimum()<<endl;
    s1.print();
    s1.print1();
    // for(;s1.IsEmpty()!=0;)
    // {
    //     cout<<s1.GetMinimum()<<"-------"<< s1.pop()<<endl;
    // }
}