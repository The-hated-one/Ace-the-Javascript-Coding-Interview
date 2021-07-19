

/*
Description

We are given a linked list where the node has two pointers. 
The first is the regular next pointer. The second 
pointer is called arbitrary_pointer and it can point to any node 
in the linked list. Your job is to write code to make a deep copy 
of the given linked list. Here, deep copy means that any operations 
on the original list (inserting, modifying and removing) should 
not affect the copied list.
*/

LinkedListNode* deep_copy_arbitrary_pointer(LinkedListNode* head) {
  if(!head) return head;
  
  LinkedListNode*current = head;
  LinkedListNode*new_head = NULL;
  LinkedListNode*new_prev = NULL;

  unordered_map<LinkedListNode*, LinkedListNode*> map;

  while(current){
    LinkedListNode*newNode = new LinkedListNode(current->data);
    newNode->arbitrary_pointer = current->arbitrary_pointer;

    if(new_prev) new_prev->next = newNode;
    else new_head = newNode;

    map[current] = newNode;

    new_prev = newNode;
    current = current->next;
  }

  // updating the arbitrary_pointer
  LinkedListNode*new_current = new_head;

  while(new_current){
    if(new_current->arbitrary_pointer){
      new_current->arbitrary_pointer = map[new_current->arbitrary_pointer];
    }
    new_current = new_current->next;
  }
  return new_head;
}
