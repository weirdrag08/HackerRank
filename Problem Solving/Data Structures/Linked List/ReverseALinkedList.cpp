

// Complete the reverse function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    if(head == NULL || head-> next == NULL){
        return head;
    }
   SinglyLinkedListNode* recursive_head = reverse(head-> next);
   head-> next-> next = head; 
   head-> next = NULL;
    
    return recursive_head;
}

