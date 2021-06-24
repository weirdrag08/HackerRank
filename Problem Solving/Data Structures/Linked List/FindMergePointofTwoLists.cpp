

// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
  /*  vector<SinglyLinkedListNode*> node_address;
    SinglyLinkedListNode *temp = head1;
    while(temp != NULL){
        temp = temp-> next;
        node_address.push_back(temp);
    }
         temp = head2;
  int size = node_address.size();
 
   while(temp != NULL){
       for(int i = 0; i < size; i++){
        if(temp == node_address[i]){
            return temp-> data;
        }
    }
    temp = temp-> next;
   }
    return 0;
    */
    unordered_map<SinglyLinkedListNode* , int> my_map;
    SinglyLinkedListNode *temp = head1;
    while(temp != NULL){
        if(my_map.count(temp) > 0){
            my_map[temp]++;
        }
        else{
            my_map[temp] = 1;
        }
        temp = temp-> next;
    }
    temp = head2;
    while(temp != NULL){
        if(my_map.count(temp) > 0){
            return temp-> data;
        }
        temp = temp-> next;
    }
    return 0;
}

