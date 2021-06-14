

// Complete the compare_lists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

   /* if(head1 == NULL && head2 == NULL){
        return true;
    }
    if((head1 == NULL && head2 != NULL) || (head2 == NULL && head1 != NULL)){
        return false;
    }
    if(head1-> data != head2-> data){
        return false;
    }
    compare_lists(head1-> next , head2-> next);
    
    return true;
*/
    SinglyLinkedListNode *temp1 = head1;
    SinglyLinkedListNode *temp2 = head2;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1-> data != temp2-> data){
            return false;
        }
        temp1 = temp1-> next;
        temp2 = temp2-> next;
    }
    if((temp1 != NULL && temp2 == NULL) || (temp2 != NULL && temp1 == NULL) ){
        return false;
    }
    return true;
}

