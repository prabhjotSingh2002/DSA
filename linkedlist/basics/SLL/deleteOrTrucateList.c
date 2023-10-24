/*This works by storing the current node in some temporary variable and freeing the current node.
 After freeing the current node, go to the next node with a temporary variable and repeat this
  process for all nodes.*/

#include"../Header.h"
#include "SLLheader.h"

void DeletionLinkedList(struct listnode ** head)
{
    struct listnode *auxilaryNode,*iterator;
    iterator=*head;

    while(iterator)
    {
        auxilaryNode=iterator->next;
        free(iterator);
        iterator=auxilaryNode;
    }

    *head=NULL;//to affect the real head back to the caller

    return;
}
/*
Time Complexity: O(n), for scanning the complete list of size n.
 Space Complexity: O(1), for creating one temporary variable
*/