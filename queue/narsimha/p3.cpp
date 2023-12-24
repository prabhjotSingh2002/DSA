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
    public:

    Queue q1;
    Queue q2;

    void push(int d)
    {
        if(q1.isEmptyQueue())
        {
            q2.enque(d);
        }
        else
        {
            q1.enque(d);
        }
    }

    int pop()
    {
        int i,size;
        if(q2.isEmptyQueue())
        {
            size=
        }
    }

};