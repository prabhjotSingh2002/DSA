//infix to postfix expression
//2+3*4 -->234*+


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
int comparePriority(int a,int b);


int main()
{
    char exp[30];
    char postfix[30]={0};
    cout<<"ENTER Infix expression"<<endl;
    cin>>exp;

    Stack s1;

    int i,j;
    for(i=0,j=0;exp[i];i++)
    {
        if(((exp[i]>='A') &&(exp[i]<='Z'))||((exp[i]>='a') &&(exp[i]<='z')))
        {
            postfix[j++]=exp[i];
        } 
        else if(exp[i]==')')
        {
            int c=s1.pop();
            while(c!='('&& c!=-1)
            {
                postfix[j++]=c;
                c=s1.pop();
            }
        }
        else
        {
                if(s1.IsEmpty())
                {
                    s1.push(exp[i]);
                }
                else
                {
                    if(exp[i]=='(')
                    {
                        s1.push(exp[i]);
                    }
                    else
                    {
                        int prev=s1.peek();
                        if(comparePriority(prev,exp[i])>0)
                        {
                            s1.push(exp[i]);
                        }
                        else
                        {
                            while(comparePriority(prev,exp[i])<=0)
                            {
                                 postfix[j++]=prev;
                                 s1.pop();
                                 if(s1.IsEmpty())
                                 {
                                    break;
                                 }
                                 prev=s1.peek();
                            }
                            s1.push(exp[i]);
                           // s1.print();
                        }

                    }
                }
        }
    }

    while(s1.IsEmpty()==0)
    {
        postfix[j++]=s1.pop();
    }
    

    cout<<"POSTFIX EXPRESSION-->"<<postfix<<endl;

}

int comparePriority(int a,int b)
{
    if((a=='+') || (a=='-'))
    {
        if((b=='*')||(b=='/'))
        {
            return 1;
        }
        else if((b=='+')||(b=='-'))
        {
            return 0;
        }
       
    }
    if((a=='*') || (a=='/'))
    {
        if((b=='*')||(b=='/'))
        {
            return 0;
        }
        else if((b=='+')||(b=='-'))
        {
            return -1;
        }
    }
}