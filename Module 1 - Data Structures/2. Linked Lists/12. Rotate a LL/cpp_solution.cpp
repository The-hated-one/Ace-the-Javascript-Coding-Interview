
/*
Description
Given the head node of a singly linked list and an integer n, 
rotate the linked list by n.
*/

typedef LinkedListNode* node_ptr;

int length(node_ptr head){
  if(!head) return 0;
  return 1 + length(head->next);
}

  node_ptr rotate(node_ptr head, int n){
    int x = length(head) - n;
    int i = 0;
    node_ptr temp = head;
    node_ptr prev = NULL;
    
    while(temp->next) temp = temp->next;

    temp->next = head;

    temp = head;

    while(i < x){
      prev = temp;
      temp = temp->next;
      i++;
    }

    prev->next = NULL;
    return temp;
  }

node_ptr rotate_list(node_ptr head, int n){
  int len = length(head);
  if(!head || len == n || len == 0) return head;

  if(n > 0){
    n = n%len;
    return rotate(head, n);
  }else{
    n = n*-1;
    n = n%len;
    return rotate(head, len-n);
  }
  return NULL;
}
