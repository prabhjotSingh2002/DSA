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

int isPalindrome(string s)
{
    int i=0;
    Stack s1;

    while(s[i]!='x')
    {
        s1.push(s[i]);
        i++;
    }
    i++;
    while(s[i])
    {
        if(s1.IsEmpty()||s[i]!=s1.pop())
        {
            cout<<"NOT PALINDROME"<<endl;
            return 0;
        }
        i++;
    }
    cout<<"PALINDROME"<<endl;
    return 1;
}

int main()
{
    isPalindrome("bbbaaaaabbbbbbxbbbbbbaaaaabbb");
}