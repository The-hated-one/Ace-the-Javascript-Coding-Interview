

using namespace std;

#include <bits/stdc++.h>

/*
Problem Statement
Given the head of a LinkedList and two positions ‘p’ and ‘q’, 
reverse the LinkedList from position ‘p’ to ‘q’.
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

class ReverseSubList {
 public:

  static ListNode*helper(ListNode*head){
    if(!head || !head->next) return head;
    ListNode*newHead = helper(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
  }

  static ListNode *reverse(ListNode *head, int p, int q) {
    if(!head) return head;

    ListNode*c1 = head;
    ListNode*p1 = NULL;

    int i = 1;
    while(i < p){
      p1 = c1;
      c1 = c1->next;
      i++;
    }

    i = 0;
    ListNode*c2 = head;
    ListNode*p2 = NULL;
    while(i < q){
      p2 = c2;
      c2 = c2->next;
      i++;
    }

    p2->next = NULL;
    ListNode*newHead = helper(c1);
    c1->next = c2;
    if(p1) p1->next = newHead;
    else return newHead;

    return head;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  ListNode *result = ReverseSubList::reverse(head, 2, 4);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}
