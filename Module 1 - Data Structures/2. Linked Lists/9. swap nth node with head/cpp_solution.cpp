

/*
Description
Given the head of a singly linked list and ‘N’, swap the head 
with the Nth node. 
Return the head of the new linked list.
*/

// Node indices starts from 1.
LinkedListNode* swap_nth_node(LinkedListNode* head, int n){
  if(!head || n == 1) return head;
  int i = 1;
  LinkedListNode *temp = head;
  LinkedListNode *prev = NULL;
  while(i < n){
    prev = temp;
    temp = temp->next;
    i++;
  }

  LinkedListNode*x = temp->next;
  temp->next = head->next;
  head->next = x;
  prev->next = head;

  return temp;
}
