#include<iostream>
using namespace std;

class ArrayQueue
{
    int front;
    int rear;
    int capacity;
    int *arr;

    public:
        
        ArrayQueue(int size=10)
        {
            capacity=size;
            front=-1;
            rear=-1;
            arr=new int[capacity];
        }

        int isEmptyQueue()
        {
            return front==-1;
        }

        int isFullQueue()
        {
            return ((rear+1)%capacity)==front;
        }

        int QueueSize()
        {
            return (capacity-front+rear+1)%capacity;
        }

        void enqueue(int data)
        {
            if(isFullQueue())
                cout<<"QUEUE OVERFLOW"<<endl;
            else
            {
                rear=(rear+1)%capacity;
                arr[rear]=data;

                if(front==-1)
                {
                    front=rear;
                }
            }
        }

        int dequeue()
        {
            int data=0;
            if(isEmptyQueue())
            {
                cout<<"queue is empty"<<endl;
                return 0;
            }
            else
            {
                data=arr[front];
                if(front==rear)
                {
                    front=rear=-1;
                }
                else
                {
                    front=(front+1)%capacity;
                }
            }
            return data;
        }

        ~ArrayQueue()
        {
            delete []arr;
        }
        

};

int main()
{
    ArrayQueue a(5);
    int n,d;
    while(1)
    {
        
        cout<<"ENTER--";
        cin>>n;

        if(n==6)
        {
            break;
        }

        switch(n)
        {
            case 1:if(a.isEmptyQueue())
                    {
                        cout<<"empty queue"<<endl;
                    }else
                    {
                        cout<<"not empty queue"<<endl;
                    }
                    break;
            case 2:if(a.isFullQueue())
                    {
                        cout<<"full queue"<<endl;
                    }else
                    {
                        cout<<"not full queue"<<endl;
                    }
                    break;
            case 3:cout<<"queue size:-->  "<<a.QueueSize()<<endl;
                    break;
            case 4:cout<<"enter data-- ";
                    cin>>d;
                    a.enqueue(d);
                    break;
            case 5:
                    cout<<"data which is dequeue"<<a.dequeue()<<endl;
                    break;
        }
    }

}