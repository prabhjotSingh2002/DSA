//stack for balancing symbol....
#include<iostream>
using namespace std;


class Stack
{
    static Stack *top;
    int data;
    Stack* next;
    public:
    Stack(){}
    Stack(int data)
    {
        this->data=data;
        next=NULL;
    }
    
    void push(int data)
    {
        Stack *n=new Stack(data);
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
        Stack *nextT=top->next;
        delete top;
        top=nextT;
        return data1;
    }

    int IsEmpty()
    {
        return top==NULL;
    }

    void peek()
    {
        cout<<"TOP data: "<<top->data<<endl;
    }

    void print()
    {
        if(top==NULL)
        {
            cout<<"STACK UNDERFLOW"<<endl;
            return;
        }
        Stack *iter=top;
        int i=0;
        while(iter)
        {
            cout<<i++<<". DATA: "<<iter->data<<endl;
            iter=iter->next;
        }
    }

};

Stack*  Stack::top=NULL;

int main()
{
    Stack s1;
    string s="((A+B)+[C+D]";
    int balancing=1,i=0;

    while(s[i])
    {
        switch(s[i])
        {
            case '(':
            case '[':
            case '{':s1.push(s[i]);
        }

        switch(s[i])
        {
            case ')':   while(s1.IsEmpty()==0)
                        {
                            int c=s1.pop();
                            if((c=='{')||(c=='['))
                            {
                                balancing=0;
                                break;                            
                            }
                            if(c=='(')
                            {
                                balancing=1;
                                break;
                            }
                        }
                        // if(balancing==0)
                        // {
                        //     cout<<"NOT A BALANCE EQUATION"<<endl;
                        // }
                        break;
            case ']':   
                        while(s1.IsEmpty()==0)
                        {
                            int c=s1.pop();
                            if((c=='(')||(c=='{'))
                            {
                                balancing=0;
                                break;                            
                            }
                            if(c=='[')
                            {
                                balancing=1;
                                break;
                            }
                        }
                        // if(balancing==0)
                        // {
                        //     cout<<"NOT A BALANCE EQUATION"<<endl;
                        // }
                        break;
            case '}':
                        while(s1.IsEmpty()==0)
                        {
                            int c=s1.pop();
                            if((c=='(')||(c=='['))
                            {
                                balancing=0;
                                break;                            
                            }
                            if(c=='{')
                            {
                                balancing=1;
                                break;
                            }
                        }
                        // if(balancing==0)
                        // {
                        //     cout<<"NOT A BALANCE EQUATION"<<endl;
                        // }
                        break;
        }

        if(balancing==0)
                break;
        i++;
    }

    
    if(s1.IsEmpty() && balancing==1)
    {
        cout<<"BALANCED EQUATION"<<endl;
    }
    else
         cout<<"NOT BALANCED EQUATION"<<endl;


}
