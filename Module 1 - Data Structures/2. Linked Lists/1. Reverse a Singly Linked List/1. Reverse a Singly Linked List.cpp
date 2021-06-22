

/*
Description

We’re given the pointer/reference to the head of a singly linked list, 
reverse it and return the pointer/reference to the 
head of the reversed linked list.
*/

LinkedListNode* reverse(LinkedListNode* head) {
  if(!head || !head->next) return head;
  LinkedListNode*newHead = reverse(head->next);
  head->next->next = head;
  head->next  = NULL;
  return newHead;
}
