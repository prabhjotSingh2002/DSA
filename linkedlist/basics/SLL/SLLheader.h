extern struct listnode **head;

void insertInLinkedList(struct listnode ** head,int data,int pos);
int ListLength(struct listnode **head);
void DeletingNodeFromLinkedList(struct listnode ** head,int pos);
void DeletionLinkedList(struct listnode ** head);

void inserting();
void deleting();
void length();
void truncate();