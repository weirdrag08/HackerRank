

// Complete the deleteNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    if(head == NULL){
        return NULL;
    }
    if(head != NULL && position == 0){
        SinglyLinkedListNode *temp = head;
        head = head-> next;
        delete temp;
    }
    else{
        int counter = 0;
        SinglyLinkedListNode *temp = head;
        while(temp != NULL && counter < position - 1){
            temp = temp-> next;
            counter++;
        }
        SinglyLinkedListNode *node_to_delete = temp-> next;
        temp-> next = node_to_delete-> next;
        node_to_delete-> next = NULL;
        delete node_to_delete;
    }
    return head;
}

