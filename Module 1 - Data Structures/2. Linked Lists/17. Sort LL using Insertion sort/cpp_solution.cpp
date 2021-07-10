

/*
Description
Given the head pointer of a linked list, sort the linked 
list in ascending order using insertion sort. 
Return the new head pointer of the sorted linked list.
*/

LinkedListNode*helper(LinkedListNode*head, LinkedListNode*node){
    if(!node) return head;

    if(!head || node->data <= head->data){
        node->next = head;
        return node;
    }

    LinkedListNode*curr = head;

    while(curr->next && curr->next->data < node->data) curr = curr->next;

    node->next = curr->next;
    curr->next = node;

    return head;
}

LinkedListNode* insertion_sort(LinkedListNode* head) {
    if(!head) return head;

    LinkedListNode*curr = head;
    LinkedListNode*sorted = NULL;
    
    while(curr){
        LinkedListNode*temp = curr->next;
        sorted = helper(sorted, curr);
        curr = temp;
    }

    return sorted;
}
