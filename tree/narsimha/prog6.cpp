#include<iostream>
#include<climits>
using namespace std;

/*ALGORITHM TO FIND SIZE OF BINARY TREE WITH &WITHOUT USING RECURSION*/

//defining binary node
class BNode
{
    public:
        int data;
        BNode *left;
        BNode *right;

        BNode()
        {
            left=NULL;
            right=NULL;
        }

    friend class BTree;  
    friend class Stack;  
    friend class Node;
    friend class Queue;
};

class Stack
{
    typedef struct Node
    {
        BNode *data;
        struct Node *next;
    } Node;
    
    Node *top; 

    public:
    Stack()
    {
        top=NULL;
    }
    
    void push( BNode *data)
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

    BNode* pop()
    {
        if(top==NULL)
        {
            cout<<"STACK UNDERFLOW"<<endl;
            return NULL;
        }
        BNode* data1=top->data;
        Node *nextT=top->next;
        delete top;
        top=nextT;
        return data1;
    }

    int IsEmpty()
    {
        return (top==NULL)?1:0;
    }

    BNode* peek()
    {
        if(top==NULL)
        {
            return NULL;
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
            cout<<i++<<". DATA: "<<(iter->data)->data<<"\t";
            iter=iter->next;
        }
    }
    friend class BTree;
};

class Node
{
    public:
    BNode* data;
    Node *next;
    
    Node()
    {
      //  data=d;
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

    

    void enque(BNode* data)
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

    BNode* dequeue()
    {
        BNode* data;
        if(front==NULL)
        {
            //queue is empty
            cout<<"QUEUE IS UNDERFLOWED";
            return NULL;
        }
        data=front->data;
        Node *t=front;
        front=front->next;
        free(t);
        return data;
    }

    // void print()
    // {
    //     Node *n=front;
    //     //int i=0;
    //     while(n)
    //     {
    //         cout<<n->data<<endl;
    //         n=n->next;
    //        // i++;
    //     }
    // }

    int isEmptyQueue()
    {
        return (front==NULL)?1:0;
    }

};

class BTree
{
    public:
        BNode  *head;

    //initialization /constructor
    BTree()
    {
        head=NULL;
    }

    //insertion Method
    void insert(int data)
    {
        insertion(&(this->head),data);
    }

    static void insertion(BNode **head,int num)
    {
        if(*head==0)
        {
            *head=new BNode;
            (*head)->data=num;
        }
        else if(num<(*head)->data)
        {
            insertion(&((*head)->left),num);
        }
        else if(num>(*head)->data)
        {
            insertion(&((*head)->right),num);
        }
        else
        {
            cout<<"DUPLICATES NOT ALLOWED\n"<<endl;
        }
    }

    static void insertionUsingTraversal(BNode **head,int num)
    {
        if(*head==0)
        {
            *head=new BNode;
            (*head)->data=num;
        }
        else
        {
            Queue q1;
            BNode *temp;
            q1.enque(*head);
            while(!q1.isEmptyQueue())
            {
                temp=q1.dequeue();

                if(temp->left)
                {
                    q1.enque(temp->left);
                }
                else
                {
                    temp->left=new BNode;
                    (temp->left)->data=num;
                    return;
                }

                if(temp->right)
                {
                    q1.enque(temp->right);
                }
                else
                {
                    temp->right=new BNode;
                    (temp->right)->data=num;
                    return;
                }
            }
        }
        return;
    }

    //preorder traversal
    //root----left---right
    void preorder()
    {
        PreOrderprint(this->head);
        cout<<endl;
        NonRecPreOrderprint(this->head);
    }
    static void PreOrderprint(BNode *root)
    {
        if(root!=NULL)
        {
            cout<<root->data<<endl;
            PreOrderprint(root->left);
            PreOrderprint(root->right);
        }   
    }
    static void NonRecPreOrderprint(BNode *root)
    {
        Stack s1;
        while(1)
        {
            while(root)
            {
                cout<<root->data<<endl;
                s1.push(root);
                root=root->left;
            }
            if(s1.IsEmpty())
            {
                break;
            }
            root=s1.pop();
            root=root->right;
        }
    }

    //inorder traversal
    //left----root---right
    void inorder()
    {
        InOrderprint(this->head);
        cout<<endl;
        NonRecInOrderprint(this->head);
    }
    static void InOrderprint(BNode *root)
    {
        if(root!=NULL)
        {
            InOrderprint(root->left);
             cout<<root->data<<endl;
            InOrderprint(root->right);
        }   
    }
    static void NonRecInOrderprint(BNode *root)
    {
        Stack s2;
        while(1)
        {
            while(root)
            {
                s2.push(root);
                root=root->left;
            }
            if(s2.IsEmpty())
            {
                break;
            }
            root=s2.pop();
            cout<<root->data<<endl;
            root=root->right;
        }
    }

    //postorder traversal
    //left----right---root
    void postorder()
    {
        PostOrderprint(this->head);
        cout<<endl;
        //NonRecPostOrderprint(this->head);
    }
    static void PostOrderprint(BNode *root)
    {
        if(root!=NULL)
        {
             PostOrderprint(root->left);
             PostOrderprint(root->right);
             cout<<root->data<<endl;
        }   
    }

    // static void NonRecPostOrderprint(BNode *root)
    // {
    //     Stack s3;
    //     while(1)
    //     {
    //         if(root)
    //         {
    //             s3.push(root);
    //             root=root->left;
    //         }
    //         else
    //         {
    //             if(s3.IsEmpty())
    //             {
    //                 cout<<"stack is empty"<<endl;
    //                 return;
    //             }
    //             else
    //             {
    //                 if((s3.peek())->right==NULL)
    //                 {
    //                     root=s3.pop();
    //                     cout<<root->data<<endl;
    //                     if(root==(s3.peek())->right)
    //                     {
    //                         cout<<(s3.peek())->right<<endl;
    //                         s3.pop();
    //                     }
    //                 }

    //                 if(!s3.IsEmpty())
    //                 {
    //                     root=(s3.peek())->right;
    //                 }
    //                 else
    //                 {
    //                     root=NULL;
    //                 }

    //             }
    //         }
    //     } 
    // }




    //level order traversal
    void LevelOrder()
    {
        printLevelOrder(this->head);
    }
    static void printLevelOrder(BNode *root)
    {
        BNode *temp;
        Queue q1;
        if(!root)
        {
            return;
        }
        q1.enque(root);

        while(!q1.isEmptyQueue())
        {
            temp=q1.dequeue();
            cout<<temp->data<<endl;
            if(temp->left)
            {
                q1.enque(temp->left);
            }
            if(temp->right)
            {
                q1.enque(temp->right);
            }
        }

    }

    int findMax()
    {
        return findMaxUsingLevelOrder(this->head);
    }

    static int findMax(BNode *root)
    {
        int rootval,left,right,max=INT_MIN;
        if(root!=NULL)
        {
            rootval=root->data;
            left=findMax(root->left);
            right=findMax(root->right);

            if(left>right)
                max=left;
            else
                max=right;

            if(rootval>max)
                max=rootval;

        }
        return max;
    }

    static int findMaxUsingLevelOrder(BNode *root)
    {
        BNode *temp;
        Queue q1;
        int max=INT_MIN;

        if(!root)
        {
            return max;
        }

        q1.enque(root);
        while(!q1.isEmptyQueue())
        {
            temp=q1.dequeue();
            //cout<<temp->data<<endl;

            if(max<temp->data)
            {
                max=temp->data;
            }

            if(temp->left)
            {
                q1.enque(temp->left);
            }
            if(temp->right)
            {
                q1.enque(temp->right);
            }
        }
        return max;
    }


    BNode *search(int data)
    {
       // return search(this->head,data);
        return searchLevelOrder(this->head,data);
    }

    static BNode *search(BNode *root,int data)
    {
        if(root)
        {
            if(root->data==data)
            {
                return root;
            }
            BNode *found=NULL;
            found=search(root->left,data);
            if(found==NULL)
            {
                found=search(root->right,data);
            }
            return found;
        }
        return NULL;
    }

    static BNode *searchLevelOrder(BNode *root,int data)
    {
        BNode *temp=NULL;
        Queue q1;
        q1.enque(root);
        while(!q1.isEmptyQueue())
        {
            temp=q1.dequeue();
            
            if(temp->data==data)
            {
                return temp;
            }

            if(temp->left)
            {
                q1.enque(temp->left);
            }
            if(temp->right)
            {
                q1.enque(temp->right);
            }
        }
        return NULL;
    }

    int size()
    {
        return sizeOfBTreeUsingLevelOrder(this->head);
    }
    static int sizeOfBTree(BNode *root)
    {
        if(root)
        {
            return 1+sizeOfBTree(root->left)+sizeOfBTree(root->right);
        }
        else
            return 0;
    }
    static int  sizeOfBTreeUsingLevelOrder(BNode *root)
    {
        Queue q1;
        int size=0;
        BNode *temp;
        if(root)
        {
            q1.enque(root);
        }
        while(!q1.isEmptyQueue())
        {
            temp=q1.dequeue();
            size++;
            if(temp->left)
            {
                q1.enque(temp->left);
            }
            if(temp->right)
            {
                q1.enque(temp->right);
            }
        }
        return size;
    }

};

int main()
{
    
    int op,num,data;
    BTree obj;
    BNode *f=NULL;
    while(1)
    {
        cout<<"\n1.to insert\n2.inorder\n3.preorder\n4.postorder\n5.level order\n6.maximum ele\n";
        cout<<"7.search node\n8.Size of tree\n9.deleteNode";
        cout<<"\nENTER : ";
        cin>>op;
        switch(op)
        {
            case 1: 
                    cout<<"ENTER NUM: ";
                    cin>>num;
                    obj.insert(num);
                    break;
            case 2:obj.inorder(); 
                    break;
            case 3:obj.preorder(); 
                    break;
            case 4:obj.postorder(); 
                    break;     
            case 5:obj.LevelOrder(); 
                    break;  
            case 6:cout<<"Maximum element: "<<obj.findMax()<<endl; 
                    break; 
            case 7: cout<<"enter element: ";
                    cin>>data;
                    if(f=obj.search(data))
                    {
                        cout<<" FOUND!!!"<<endl;
                        cout<<"---LEVELORDER---"<<endl;
                        obj.printLevelOrder(f);
                    } 
                    else
                    {
                        cout<<"NOT FOUND!!"<<endl;
                    }
                    break; 
            case 8:cout<<"SIZE OF BTREE--> "<<obj.size()<<endl;
                    break; 
            default:printf("ENTER CORRECT OP\n");
        }
    }
}

