
/*
Description
 
Given the head nodes of two linked lists that may or may not intersect, 
find out if they do in fact intersect and return the 
point of intersection. Return null otherwise.
*/

int length(LinkedListNode*head){
  if(!head) return 0;
  return 1 + length(head->next);
}

LinkedListNode* intersect(LinkedListNode* head1, LinkedListNode* head2) {
  
  if(!head1 || !head2) return NULL;

  LinkedListNode*h1 = NULL;
  LinkedListNode*h2 = NULL;

  int len1 = length(head1);
  int len2 = length(head2);
  int difference = 0;

  if(len1 >= len2){
    difference = len1 - len2;
    h1 = head1;
    h2 = head2;
  }else{
    difference = len2 - len1;
    h1 = head2;
    h2 = head1;
  }

  while(difference > 0){
    h1 = h1->next;
    difference--;
  }

  while(h1){
    if(h1 == h2) return h1;
    h1 = h1->next;
    h2 = h2->next;
  }

  return NULL;
}
