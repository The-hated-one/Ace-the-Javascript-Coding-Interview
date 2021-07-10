
/*
Description
Merge sort is one of the standard sorting algorithms for 
a Linked List. If the given linked list is 29 -> 23 -> 82 -> 11, 
then the sorted (in ascending order) 
list should be 11 -> 23 -> 29 -> 82.
*/

// Time Complexity : O(nlogn)
// Space Complexity : O(logn)

typedef LinkedListNode* node_ptr;

node_ptr merge(node_ptr head1, node_ptr head2){
  if(!head1) return head2;
  if(!head2) return head1;
  if(!head1 && !head2) return NULL;

  node_ptr newHead = NULL;
  node_ptr tail = NULL;

  if(head1->data <= head2->data){
    newHead = tail = head1;
    head1 = head1->next;
  }else{
    newHead = tail = head2;
    head2 = head2->next;
  }

  while(head1 && head2){
    if(head1->data <= head2->data){
      tail->next = head1;
      head1 = head1->next;
    }else{
      tail->next = head2;
      head2 = head2->next;
    }
    tail = tail->next;
  }

  if(!head1) tail->next = head2;
  if(!head2) tail->next = head1;

  return newHead;
}

node_ptr midpointLL(node_ptr head){
  if(!head) return head;
  node_ptr fast = head;
  node_ptr slow = head;
  
  while(fast->next && fast->next->next){
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}

node_ptr merge_sort(node_ptr head) {
  if(!head || !head->next) return head;
  node_ptr mid = midpointLL(head);
  node_ptr head1 = head;
  node_ptr head2 = mid->next;
  mid->next = NULL;
  head1 = merge_sort(head1);
  head2 = merge_sort(head2);
  return merge(head1, head2);
} 
