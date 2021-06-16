

// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
     
     SinglyLinkedListNode *head = NULL;
     SinglyLinkedListNode *tail = NULL;

        if(head1-> data < head2-> data){
            head = head1;
            tail = head1;
           head1 = head1-> next;
        }
        else{
            head = head2;
             tail = head2;
            head2 = head2-> next;
        }

     while(head1 != NULL && head2 != NULL){
         if(head1-> data < head2-> data){
        tail-> next = head1;
         tail = head1;
        head1 = head1-> next;
     } 
     else{
         tail-> next = head2;
         tail = head2;
        head2 = head2-> next;
     }

     }
   if(head1 != NULL){
       tail->next = head1;  
   }
   if(head2 != NULL){
       tail-> next = head2;
   }
    
    return head;
}

