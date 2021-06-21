

// Complete the has_cycle function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool has_cycle(SinglyLinkedListNode* head) {
    if(head == NULL){
        return false;
    }
    SinglyLinkedListNode *slow = head, *fast = head;
    bool cycle = false;
    while(fast != NULL && fast-> next != NULL){
        slow = slow-> next;
        fast = fast-> next-> next;
        if(slow == fast){
            cycle = true;
            break;
        }
    }
    return cycle;
}

