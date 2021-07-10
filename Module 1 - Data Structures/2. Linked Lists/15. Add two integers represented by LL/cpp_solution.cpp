
/*
Description
Given the head pointers of two linked lists where each 
linked list represents an integer number (each node is a digit), 
add them and return the resulting linked list. Here, the first 
node in a list represents the least significant digit.
*/

LinkedListNode* add_integers(LinkedListNode* head1, LinkedListNode* head2) {
  if(!head1) return head2;
  if(!head2) return head1;
  if(!head1 && !head2) return NULL;

  LinkedListNode*newHead = NULL, *tail = NULL;
  int carry = 0;

  while(head1 && head2){
    int x = head1->data + head2->data + carry;
    carry = x/10;
    int y = x%10;
    LinkedListNode*newNode = new LinkedListNode(y);
    if(!newHead) newHead = tail = newNode;
    else{
      tail->next = newNode;
      tail = tail->next;
    }
    head1 = head1->next;
    head2 = head2->next;
  }

  // head2 has ended
  while(head1){
    int x = head1->data + carry;
    carry = x/10;
    int y = x%10;
    LinkedListNode*newNode = new LinkedListNode(y);
    tail->next = newNode;
    tail = tail->next;
    head1 = head1->next;
  }

  // head1 has ended
  while(head2){
    int x = head2->data + carry;
    carry = x/10;
    int y = x%10;
    LinkedListNode*newNode = new LinkedListNode(y);
    tail->next = newNode;
    tail = tail->next;
    head2 = head2->next;
  }

  if(carry > 0){
    LinkedListNode*newNode = new LinkedListNode(carry);
    tail->next = newNode;
    tail = tail->next;
  }

  tail->next = NULL;

  return newHead;

}
