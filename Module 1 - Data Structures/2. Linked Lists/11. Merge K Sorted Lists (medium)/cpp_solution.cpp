

#include<bits/stdc++.h>
using namespace std;

/*
Problem Statement
Given an array of ‘K’ sorted LinkedLists, merge them into one sorted list.

Example 1:
Input: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4]
Output: [1, 2, 3, 3, 4, 6, 6, 7, 8]

Example 2:
Input: L1=[5, 8, 9], L2=[1, 7]
Output: [1, 5, 7, 8, 9]
*/


class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

class MergeKSortedLists {
 public:
  static ListNode *merge(const vector<ListNode *> &lists) {
  
    priority_queue <int, vector<int>, greater<int> > pq;
    for(auto head : lists){
      while(head){
        pq.push(head->value);
        head = head->next;
      }
    }

    ListNode *newHead = NULL;
    ListNode *tail = NULL;

    while(!pq.empty()){
      ListNode*newNode  = new ListNode(pq.top());
      pq.pop();
      if(!newHead) newHead = tail = newNode;
      else{
        tail->next = newNode;
        tail = tail->next;
      }
    }
    return newHead;
  }
};

int main(int argc, char *argv[]) {
  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(6);
  l1->next->next = new ListNode(8);

  ListNode *l2 = new ListNode(3);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(7);

  ListNode *l3 = new ListNode(1);
  l3->next = new ListNode(3);
  l3->next->next = new ListNode(4);

  ListNode *result = MergeKSortedLists::merge(vector<ListNode *>{l1, l2, l3});
  cout << "Here are the elements form the merged list: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}
