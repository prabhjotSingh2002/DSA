#include"../Header.h"
#include "SLLheader.h"
/*The ListLength() function takes a linked list as input and counts the number of nodes in the list*/
/*
Time Complexity: O(n), for scanning the list of size n.
 Space Complexity: O(1), for creating a temporary variable.
*/
int ListLength(struct listnode **head)
{
    struct listnode *current =*head;
    int count =0;

    while(current!=NULL)
    {
        count++;
        current=current->next;
    }
    return count;
}


