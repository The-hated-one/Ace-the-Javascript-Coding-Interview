
/*
Description #
Given a singly linked list, reverse the nodes 
at even indices (starting at 1). 
*/

// Helper function to merge two lists.
LinkedListNode* merge_alternating(LinkedListNode* list1, LinkedListNode* list2) {
  if (list1 == nullptr) {
    return list2;
  }

  if (list2 == nullptr) {
    return list1;
  }

  LinkedListNode* head = list1;

  while (list1->next != nullptr && list2 != nullptr) {
    LinkedListNode* temp = list2;
    list2 = list2->next;

    temp->next = list1->next;
    list1->next = temp;
    list1 = temp->next;
  }

  if (list1->next == nullptr) {
    list1->next = list2;
  }

  return head;
}

LinkedListNode* reverse_even_nodes(LinkedListNode* head) {

  // Let's extract even nodes from the existing
  // list and create a new list consisting of 
  // even nodes. We will push the even nodes at
  // head since we want them to be in reverse order.

  LinkedListNode* curr = head;
  LinkedListNode* list_even = nullptr;

  while (curr != nullptr && curr->next != nullptr) {
    LinkedListNode* even = curr->next;
    curr->next = even->next;

    // Push at the head of new list.
    even->next = list_even;
    list_even = even;

    curr = curr->next;
  }

  // Now, merge the two lists
  // Original: 1,2,3,4,5
  // Modified original: 1,3,5
  // List_even: 4,2
  // Merged: 1,4,3,2,5

  return merge_alternating(head, list_even);
}

int main() {
  vector<int> v1 = {7, 14, 21, 28, 9};
  LinkedListNode* list_head = LinkedList::create_linked_list(v1);
  
  cout << "Original list: ";
  LinkedList::display(list_head);

  list_head = reverse_even_nodes(list_head);
  cout <<"After reversing even nodes: ";
  LinkedList::display(list_head);
}
