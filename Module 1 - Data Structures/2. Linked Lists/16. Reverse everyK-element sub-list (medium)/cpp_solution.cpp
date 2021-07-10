

using namespace std;

#include <iostream>

/*
Problem Statement
Given the head of a LinkedList and a number ‘k’, reverse every ‘k’ 
sized sub-list starting from the head.
If, in the end, you are left with a sub-list with less than ‘k’ 
elements, reverse it too.
*/

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class ReverseEveryKElements {
 public:
  static ListNode *reverse(ListNode *head, int k) {
    
    ListNode*fwd = NULL, *curr = head, *prev = NULL;
    int i = 0;
    while(i < k && curr){
      fwd = curr->next;
      curr->next = prev;
      prev = curr;
      curr = fwd;
      i++;
    }

    if(fwd) head->next = reverse(fwd, k);
    return prev;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);
  head->next->next->next->next->next->next = new ListNode(7);
  head->next->next->next->next->next->next->next = new ListNode(8);

  ListNode *result = ReverseEveryKElements::reverse(head, 3);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}
