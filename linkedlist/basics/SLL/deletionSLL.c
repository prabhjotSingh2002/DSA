#include"../Header.h"
#include "SLLheader.h"
/*
Similar to insertion, here we also have three cases. 
• Deleting the first node 
• Deleting the last node
 • Deleting an intermediate node.
*/

void DeletingNodeFromLinkedList(struct listnode ** head,int pos)
{
    int k=1;
    struct listnode *p,*q;

    if(*head==NULL)
    {
        printf("List is Empty\n");
        return;
    }
    p=*head;
    if(pos==1)//from beginning
    {
        *head=(*head)->next;
        free(p);
        return;
    }
    else
    {
        //traverse the list until we reach position
        while((p!=NULL)&&(k<pos))
        {
            k++;
            q=p;
            p=p->next;
        }
        if(p==NULL)//at the end
        {
            printf("Position doesnot exist\n");
        }
        else//from the middle
        {
            q->next=p->next;
            free(p);
        }
    }
    return;
}
/*Time Complexity: O(n). In the worst case, we may need to delete the node at the end of the list.
 Space Complexity: O(1), for one temporary variable.*/