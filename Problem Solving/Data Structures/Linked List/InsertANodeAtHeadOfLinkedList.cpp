

// Complete the insertNodeAtHead function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {

    if(llist == NULL){
        SinglyLinkedListNode *new_node = new SinglyLinkedListNode(data);
        llist = new_node;
    }
    else{
        SinglyLinkedListNode *new_node = new SinglyLinkedListNode(data);
        new_node-> next = llist;
        llist = new_node;
    }
    return llist;
}

