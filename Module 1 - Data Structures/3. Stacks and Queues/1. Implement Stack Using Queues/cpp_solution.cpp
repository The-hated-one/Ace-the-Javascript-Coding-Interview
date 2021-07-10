

/*
Description

A stack is a data structure in which objects are inserted and 
removed according to the LIFO (Last In First Out) principle. 
An item is added at the top of the stack and removed from 
the top as well. There are two important 
functionalities in the stack: push() and pop().
1. push() means to insert an item at the top of the stack.
2. pop() means to remove an item from the top of the stack.

A queue is a data structure in which objects are inserted 
and removed according to the FIFO (First In First Out) principle. 
An item is added at the back of the queue and 
removed from the front. 
There are two important functionalities 
in the queue: enque() and deque().
1. enqueue() means to insert an item at the back of the queue.
2. dequeue() means to remove an item from the front of the queue.

Suppose we have a Queue class that provides all common 
operations such as enqueue(), dequeue(), and size().

Using the instances of this Queue class, implement a Stack 
class with its push(), pop(), and isEmpty() operations.

NOTE : If the stack is empty, the pop() function should return -1.
*/S

class StackUsingQueue{
  //Write - Your - Code
  queue<int> q;
  public:
    void push(int data) {
      q.push(data);
      
      for(int i = 0; i < q.size()-1; i++){
        q.push(q.front());
        q.pop();
      }
    }

    bool is_empty() {
      return q.empty();
    }

    int pop() {
      if(q.empty()) return -1;
      int ele = q.front();
      q.pop();
      return ele;
    }
};
