
//https://www.educative.io/module/lesson/data-structures-in-javascript/7DZ6JnE2YzB


int length(LinkedListNode*head){
  if(!head) return 0;
  return 1 + length(head->next);
}

LinkedListNode*reverse(LinkedListNode*head){
  if(!head || !head->next) return head;
  LinkedListNode*newHead = reverse(head->next);
  head->next->next = head;
  head->next = NULL;
  return newHead;
}

LinkedListNode*reverseK(LinkedListNode*head, int k){
  LinkedListNode*curr = head, *prev = NULL, *fwd = NULL;
  int i = 0;
  while(i < k && curr){
    fwd = curr->next;
    curr->next = prev;
    prev = curr;
    curr = fwd;
    i++;
  }

  if(fwd) head->next = reverseK(fwd, k);
  return prev;
}

LinkedListNode* reverse_k_nodes(LinkedListNode* head, int k) {
  if(!head) return head;
  if(k <= 1) return head;
  int n = length(head);
  if(k >= n) return reverse(head);

  return reverseK(head, k);
}
