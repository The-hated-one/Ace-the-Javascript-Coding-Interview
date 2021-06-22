
/*
Description
We are given a linked list of integers and we have to remove 
all the duplicate nodes from it by keeping only the first 
occurrence of each duplicate. 
*/

LinkedListNode* remove_duplicates(LinkedListNode* head){
  if(!head) return head;
  LinkedListNode*temp = head;
  LinkedListNode*prev = NULL;
  unordered_map<int, int> mp;
  int flag = 0;
  while(temp){
    if(mp[temp->data] == 1) flag = 1;
    else{
      if(flag == 1){
        prev->next = temp;
        flag = 0;
      }
      mp[temp->data] = 1;
      prev = temp;
    }
    temp = temp->next;
  }
  prev->next = NULL;
  return head;
}
