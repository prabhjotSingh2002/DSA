#include<iostream>
#include<climits>
using namespace std;

/*ALGORITHM TO FIND FULL NODES & HALF NODE IN A TREE */


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
    void LevelOrder(int f=0)
    {
        if(f==0)
            printLevelOrder(this->head);
        else
            printRevLevelOrder(this->head);
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

    static void printRevLevelOrder(BNode *root)
    {
        BNode *temp;
        Stack s1;
        Queue q1;
        if(!root)
        {
            return;
        }
        q1.enque(root);

        while(!q1.isEmptyQueue())
        {
            temp=q1.dequeue();
            s1.push(temp);
            //cout<<temp->data<<endl;
            if(temp->left)
            {
                q1.enque(temp->left);
            }
            if(temp->right)
            {
                q1.enque(temp->right);
            }
        }
        while(!s1.IsEmpty())
        {
            cout<<(s1.pop())->data<<endl;
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

    void deleteTree()
    {
        deleteTree(this->head);
        this->head=NULL;
    }
    static void deleteTree(BNode *root)
    {
        if(root==NULL)
            return;
        //it will follow postorder approch
        //first delete subtrees
        deleteTree(root->left);
        deleteTree(root->right);

        //after that delete current node;
        delete root;
    }

    int FindDepth()
    {
        return findHieght(this->head);
    }
    int FindHiegth()
    {
        //return findHieght(this->head);
        return findHieghtUsingLevelOrder(this->head);
    }

    static int findHieght(BNode *root)
    {
        if(root==NULL)
            return 0;
        else
        {
            int lhieght,rhieght;
            lhieght=findHieght(root->left);
            rhieght=findHieght(root->right);
            if(lhieght>rhieght)
            {
                return (lhieght+1);
            }
            else
                return (rhieght+1);
        }
    }
    static int findHieghtUsingLevelOrder(BNode *root)
    {
        int level=1;
        Queue q1;
        if(root==NULL)
            return 0;
        q1.enque(root);
        //end of level 1
        q1.enque(NULL);
        BNode *temp;
        while(!q1.isEmptyQueue())
        {
            temp=q1.dequeue();
            if(temp==NULL)
            {
                //completion of another level & put a mark indication for another level
                if(!q1.isEmptyQueue())
                {
                    q1.enque(NULL);
                }
                level++;
            }
            else
            {
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
        return level-1;
    }

    BNode* deepestNode()
    {
        return deepestNode(this->head);
    }

    BNode *deepestNode(BNode *root)
    {
        Queue q1;
        BNode *temp=NULL;
        if(root==NULL)
        {
            return NULL;
        }
        q1.enque(root);
        while(!q1.isEmptyQueue())
        {
            temp=q1.dequeue();
            if(temp->left)
            {
                q1.enque(temp->left);
            }
            if(temp->right)
            {
                q1.enque(temp->right);
            }
        }
        return temp;
    }

    int countLeafNode()
    {
        return countLeafNode(this->head);
    }
    static int countLeafNode(BNode *root)
    {
        Queue q1;
        int count=0;
        BNode *temp;
        if(root==NULL)
        {
            return 0;
        }
        q1.enque(root);
        while(!q1.isEmptyQueue())
        {
            temp=q1.dequeue();
            if(temp->left==NULL && temp->right==NULL)
            {
                count++;
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
        return count;
    }

    BNode *findParent(int n)
    {
        return findParent(this->head,n);
    }

   static BNode *findParent(BNode *ptr,int n)
    {
        static BNode * Parent=NULL;
        if(ptr)
        {
            if(ptr->data==n)
            {
                return Parent;
            }
            else if( n < ptr->data)
            {
                Parent=ptr;
                return findParent(ptr->left,n); 
            }  
            else if(n > ptr->data){
                Parent=ptr;
                return  findParent(ptr->right,n);
            }
        }
        return NULL;
    }

    void deleteNode(int n)
    {
        deleteNode(&(this->head),n);
    }
    void deleteNode(BNode **ptr,int n)
    {
        if(*ptr)
        {
            BNode *del=search(*ptr,n);
            BNode *p=findParent(*ptr,n);

            if(del)
            {
                ///leaf node detection
            abc:if(del->left==NULL && del->right==NULL)
                {
                    if(del==p->left)
                    {
                        p->left=NULL;
                    }
                    else if(del==p->right)
                    {
                        p->right=NULL;
                    }

                    delete del;
                    return;
                }

                //delete a node which is having left child always
                if(del->left!=NULL && del->right==NULL)
                {
                    if(del==p->left)
                    {
                       p->left=del->left;
                    }
                    else if(del==p->right)
                    {
                        p->right=del->left;
                    }
                    delete del;
                    return;
                }

                //delete a node which is having right child always
                if(del->left==NULL && del->right!=NULL)
                {
                    if(del==p->left)
                    {
                       p->left=del->right;
                    }
                    else if(del==p->right)
                    {
                        p->right=del->right;
                    }
                    delete del;
                    return;
                }

                //deleteing a node with two child
                if(del->left!=NULL && del->right!=NULL)
                {
                    BNode *max;
                    max=del->left;
                    p=del;
                    while(max->right)
                    {
                        p=max;
                        max=max->right;
                    }
                    del->data=max->data;
                    del=max;
                    goto abc;
                }

            }
            else
            {
                cout<<"NODE NOT FOUND\n"<<endl;
            }
        }
        else
        {
            cout<<"NO RECORD FOUND!!!"<<endl;
        }
    }

    int countFullNode(int i=0)
    {
        return countFullNode(this->head,i);
    }

    static int countFullNode(BNode *root,int i)
    {
        Queue q1;
        int c1=0,c2=0,c3=0;
        BNode *temp;
        q1.enque(root);
        while(!q1.isEmptyQueue())
        {
            temp=q1.dequeue();
            if(temp->left!=NULL && temp->right!=NULL)
            {
                c1++;
            }
            if(temp->left==NULL && temp->right==NULL)
            {
                c2++;
            }
            if(temp->left==NULL && temp->right!=NULL)
            {
                c3++;
            }
            if(temp->left!=NULL && temp->right==NULL)
            {
                c3++;
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

        if(i==0)
            return c1;
        else if(i==1)
            return c2;

        return c3;
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
        cout<<"7.search node\n8.Size of tree\n9.reverse Level Order\n10.deleteTree\n";
        cout<<"11.Hieght/depth of tree\n12.deepest Node\n13.count leaf node\n14. DeleteNode\n";
        cout<<"15.Find Parent\n16.Full Node Count\n17.Half Node Count";
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
            case 9:obj.LevelOrder(3);
                    break;
            case 10:obj.deleteTree();
                    cout<<" TREE HAS BEEN DELETED  "<<endl;
                    break;
            case 11:cout<<"Hieght or Depth of tree--> "<<obj.FindHiegth()<<endl;
                    break;
            case 12:if(f=obj.deepestNode())
                    {
                        obj.printLevelOrder(f);
                    }
                    else
                    {
                        cout<<"TREE NOT EXIST"<<endl;
                    }
                    break;
            case 13:cout<<"LEAF NODE COUNT---> "<<obj.countLeafNode()<<endl;
                    break;
            case 14:cout<<"enter element you want to delete: ";
                    cin>>data;
                    obj.deleteNode(data);
                    break;
            case 15:
                    cout<<"enter element: ";
                    cin>>data;
                    if(f=obj.findParent(data))
                    {
                        obj.printLevelOrder(f);
                    }
                    else
                    {
                        cout<<"Parent Node not EXIST"<<endl;
                    }
                    break;
            case 16:cout<<"Count of full Node-->"<<obj.countFullNode()<<endl;
                    break;
            case 17:cout<<"Count of half Node-->"<<obj.countFullNode(2)<<endl;
                    break;
            default:printf("ENTER CORRECT OP\n");
        }
    }
}

