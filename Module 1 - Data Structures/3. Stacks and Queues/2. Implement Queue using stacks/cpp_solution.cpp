
/*
Description
Suppose we have a Stack class that provides all common operations 
like push(), pop(), isEmpty()/empty().
Using the instances of this Stack class, implement a Queue class 
with its enqueue(), dequeue(), and isEmpty() operations.
If the queue is empty, the dequeue() function should return -1.
*/

class QueueUsingStack{
  public:
    stack<int> stack1;
    stack<int> stack2;

    void enqueue(int data) {
      stack1.push(data);
    }

    bool is_empty() {
      return (stack1.size() + stack2.size()) == 0;
    }

    int dequeue() {
      int val = -1;

      if(is_empty()) {
        return -1;
      }

      if(stack2.empty()) {
        while(!stack1.empty()){
          int temp = stack1.top();
          stack1.pop();
          stack2.push(temp);
        }
      }

      val = stack2.top();
      stack2.pop();
      return val;
    }
};

int main(){
  QueueUsingStack qs;
  cout << "dequeue()" << " = " << qs.dequeue() << endl;
  qs.enqueue(3);
  qs.enqueue(6);
  qs.enqueue(16);
  cout << "dequeue()" << " = " << qs.dequeue() << endl;
  qs.enqueue(8);
  qs.enqueue(4);
  cout << "dequeue()" << " = " << qs.dequeue() << endl;
}
