//program to reverse the queue
#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    
    Node(int d=0)
    {
        data=d;
        next=NULL;
    }
};
class Queue
{
    public:
    Node *rear;
    Node *front;

    Queue()
    {
        rear=front=NULL;
    }

    void enque()
    {
        Node* temp=new Node;
        cout<<"Enter data : ";
        cin>>temp->data;
        cout<<endl;

        if(front==NULL)
        {
            //queue is empty
            front=temp;
            rear=front;
            return;
        }
        rear->next=temp;
        rear=temp;
      //  rear->next=NULL;
    }

    void enque(int data)
    {
        Node* temp=new Node;
        temp->data=data;
        //cout<<endl;

        if(front==NULL)
        {
            //queue is empty
            front=temp;
            rear=front;
            return;
        }
        rear->next=temp;
        rear=temp;
      //  rear->next=NULL;
    }

    int dequeue()
    {
        int data;
        if(front==NULL)
        {
            //queue is empty
            cout<<"QUEUE IS UNDERFLOWED";
            return -1;
        }
        data=front->data;
        Node *t=front;
        front=front->next;
        free(t);
        return data;
    }

    void print()
    {
        Node *n=front;
        //int i=0;
        while(n)
        {
            cout<<n->data<<endl;
            n=n->next;
           // i++;
        }
    }

    int isEmptyQueue()
    {
        return (front==NULL)?1:0;
    }

};
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

void reverseQueue(Queue &p)
{
    Stack q;
    while(!p.isEmptyQueue())
    {
        q.push(p.dequeue());
    }
    while(!q.IsEmpty())
    {
        p.enque(q.pop());
    }
}

int main()
{
    Queue a;
    int i;
    for(i=0;i<6;i++)
    {
        a.enque();
    }
    
    a.print();

    // for(i=0;i<3;i++)
    // {
    //     cout<<a.dequeue()<<endl;
    // }
    reverseQueue(a);
    a.print();


}

