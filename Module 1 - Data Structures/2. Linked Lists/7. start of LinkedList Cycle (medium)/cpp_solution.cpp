
/*
Problem Statement

Given the head of a Singly LinkedList that contains a cycle, 
write a function to find the starting node of the cycle.
*/

using namespace std;

#include <iostream>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class LinkedListCycleStart {
 public:
  static ListNode *findCycleStart(ListNode *head) {
    if(!head) return head;
    ListNode*fast = head;
    ListNode*slow = head;

    while(fast && fast->next){
      fast = fast->next->next;
      slow = slow->next;

      if(fast == slow) break;
    }

    slow = head;

    while(fast != slow){
      fast = fast->next;
      slow = slow->next;
    }

    return slow;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);

  head->next->next->next->next->next->next = head->next->next;
  cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;

  head->next->next->next->next->next->next = head->next->next->next;
  cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;

  head->next->next->next->next->next->next = head;
  cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;
}
