//maximum sum in sliding window
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
            cout<<n->data<<"  ";
            n=n->next;
           // i++;
        }
        cout<<endl;
    }

    int isEmptyQueue()
    {
        return (front==NULL)?1:0;
    }

};


int main()
{
    int A[]={1,3,-1,-3,5,3,6,7};
    Queue q;
    int maxA[8-2]={0};

    int i,j;
    int max=A[0],smax=A[0];
    for(i=0,j=0;i<8;i++)
    {
        if(i>=3)
        {
           if(q.dequeue()==max)
           {
                max=smax;
           }
           maxA[j++]=max;
        }
        if(A[i]>max)
        {
            smax=A[i];
            max=A[i];
        }
        else if(A[i]>smax)
        {
            smax=A[i];
        }
        //cout<<"max= "<<max<<"smax: "<<smax<<endl;
        q.enque(A[i]);
    }
    maxA[j]=max;
    for(int k=0;k<6;k++)
        cout<<maxA[k]<<endl;
}