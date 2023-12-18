#include<iostream>
using namespace std;

class ListNode
{
    public:
    int data;
    ListNode * next;
};

class Queue
{
    public:
    ListNode *front;
    ListNode *rear;
    
    Queue ()
    {
        ListNode *temp=new ListNode();
        front=rear=NULL;
    }
    int isEmptyQueue()
    {
        return front==NULL;
    }
    void enque(int data)
    {
        ListNode *newNode=new ListNode();
        newNode->data=data;
        newNode->next=NULL;
        rear->next=newNode;
        rear=newNode;
        if(front==NULL)
            front=rear;
    }

    int dequeue()
    {
        int data=0;
        ListNode *temp;
        if(isEmptyQueue())
        {
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        else
        {
            temp=front;
            data=front->data;
            front=front->next;
            delete temp;
        }
        return data;
    }  

    void deleteQueue()
    {
        ListNode *temp;
        while(this)
        {
            temp=this;
            this=this->next;
            delete temp;
        }
        delete this;
    }

};