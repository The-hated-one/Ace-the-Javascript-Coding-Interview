


int length(LinkedListNode*head){
  if(!head) return 0;
  return 1 + length(head->next);
}

/*
Description
Given a singly linked list, return the nth node from last. 
Return null if ‘n’ is out-of-bounds.
*/

LinkedListNode* find_nth_from_last(LinkedListNode* head, int n) {
  if(!head) return head;
  int len = length(head);

  if(n > len) return NULL;
  else{
    int x = len - n;
    int i = 0;
    while(i < x){
      head = head->next;
      i++;
    }
    return head;
  }
  return head;
}
