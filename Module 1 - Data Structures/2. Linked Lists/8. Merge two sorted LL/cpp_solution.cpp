

/*
Description
Given two sorted linked lists, 
merge them so that the resulting linked list is also sorted.
*/

typedef LinkedListNode* node;
node merge_sorted(node head1, node head2) {
  if(!head1) return head2;
  if(!head2) return head1;
  if(!head1 && !head2) return NULL;

  node newHead = NULL;
  node tail = NULL;

  if(head1->data <= head2->data){
    newHead = head1;
    tail = head1;
    head1 = head1->next;
  }else{
    newHead = head2;
    tail = head2;
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
