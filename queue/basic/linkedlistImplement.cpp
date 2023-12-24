#include<iostream>
using namespace std;

class ListNode
{
    public:
    int data;
    ListNode * next;

    ListNode()
    {
        data=0;
        next=NULL;
    }
};

class Queue
{
    public:
    ListNode *front;
    ListNode *rear;
    
    Queue ()
    {
        ListNode *temp=new ListNode();
        front=new ListNode();
        rear=new ListNode();
    }
    int isEmptyQueue()
    {
        return (front->next==NULL)?1:0;
    }
    void enque(int data)
    {
        ListNode *newNode=new ListNode();
        newNode->data=data;
        newNode->next=NULL;
        rear->next=newNode;
        rear=newNode;
        if(front->next==NULL)
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
            temp=this->front;
            this->front=(this->front)->next;
            delete temp;
        }
        delete this;
    }

};

int main()
{
    Queue a;
    if(a.isEmptyQueue()!=0)
    {
        cout<<"Empty Queue"<<endl;
    }
}