//postfix evaluation using stack

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

int isOperator(char a)
{
    switch(a)
    {
        case '+':
        case '-':
        case '/':
        case '*':
                    return 1;
                    break;
        default:
                    return 0;
    }
    return 0;
}

int main()
{
    char exp[30];
    cout<<"ENTER postfix expression"<<endl;
    cin>>exp;

    Stack s1;

    int i;

    for(i=0;exp[i];i++)
    {
        if('0'<=exp[i] && exp[i]<='9')
        {
            s1.push(exp[i]-'0');
        }
        else if(isOperator(exp[i]))
        {
                int oper1=s1.pop();
                int oper2=s1.pop();

                switch(exp[i])
                {
                    case '+':s1.push(oper2+oper1);
                                break;
                    case '-':s1.push(oper2-oper1);
                                break;
                    case '/':s1.push(oper2/oper1);
                                break;
                    case '*':s1.push(oper2*oper1);
                                break;
                }
        }
    }

    cout<<"ANSWER-->"<<s1.pop()<<endl;
}