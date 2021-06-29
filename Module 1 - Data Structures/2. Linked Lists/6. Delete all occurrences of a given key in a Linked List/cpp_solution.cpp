


/*
Description

We are given the head of a linked list and a key. 
We have to delete the node that contains this given key.
*/

LinkedListNode* delete_node(LinkedListNode* head, int key) {
  if(!head) return head;
  if(head->data == key) return head->next;
  head->next = delete_node(head->next, key);
  return head;
}
