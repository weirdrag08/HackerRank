

// Complete the insertNodeAtTail function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
      
       
      
        SinglyLinkedListNode *new_node = new SinglyLinkedListNode(data);
        if(head == NULL){
            head = new_node;
        }
        else{
            SinglyLinkedListNode *tail = head;
             while(tail-> next != NULL){
            tail = tail-> next;
        }
            tail -> next = new_node;
        }

        return head;
}

