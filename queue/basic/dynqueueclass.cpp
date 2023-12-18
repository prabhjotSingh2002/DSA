#include<iostream>
#include<cstdlib>
using namespace std;

class DynArrayQueue
{
    int front;
    int rear;
    int capacity;
    int *arr;

    public:
        
        DynArrayQueue(int size=10)
        {
            capacity=size;
            front=-1;
            rear=-1;
            arr=(int *)malloc(capacity*sizeof(int));
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
                ResizeQueue();
            
            rear=(rear+1)%capacity;
            arr[rear]=data;

            if(front==-1)
            {
                front=rear;
            }
            
        }

        void ResizeQueue()
        {
            int size=capacity;
            capacity=capacity*2;
            arr=(int *)realloc(arr,capacity);
            if(front>rear)
            {
                for(int i=0;i<front;i++)
                {
                    arr[i+size]=arr[i];
                }
                rear=rear+size;
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

        ~DynArrayQueue()
        {
            delete []arr;
        }
        

};



