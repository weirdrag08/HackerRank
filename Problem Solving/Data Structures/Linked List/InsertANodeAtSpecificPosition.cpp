

// Complete the insertNodeAtPosition function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    if(head == NULL && position == 0){
        SinglyLinkedListNode* new_node = new SinglyLinkedListNode(data);
        return new_node;
    }
    if(head != NULL && position == 0){
        SinglyLinkedListNode* new_node = new SinglyLinkedListNode(data);
        new_node-> next = head;
        head = new_node;
    }
    else{
        int counter = 0;
        SinglyLinkedListNode *temp = head;
        while(temp-> next != NULL && counter < position - 1){
            temp = temp-> next;
            counter++;
        }
        if(temp != NULL){
           SinglyLinkedListNode* new_node = new SinglyLinkedListNode(data);
           new_node-> next = temp-> next;
           temp-> next = new_node; 
        }
    }
    return head;
}

