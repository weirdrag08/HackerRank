

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    vector<Node*>* path_finder(Node *root , int v){
       if(root == NULL){
           return NULL;
       }
       if(root-> data == v){
           vector<Node*> *path = new vector<Node*>();
           path-> push_back(root);
           return path;
       }
     vector<Node*> *left_path = path_finder(root-> left , v);
     if(left_path != NULL){
         left_path-> push_back(root);
         return left_path;
     }
     vector<Node*> *right_path = path_finder(root-> right , v);
     if(right_path != NULL){
         right_path-> push_back(root);
         return right_path;
     }
     else{
         return NULL;
     }
    }
  
    Node *lca(Node *root, int v1,int v2) {
		// Write your code here.
      
       vector<Node*> *path_to_v1 = path_finder(root , v1);
       vector<Node*> *path_to_v2 = path_finder(root , v2);

        int v1_size = path_to_v1-> size();
        int v2_size = path_to_v2-> size();
        Node* count_arr[25];

       for(int i = 0; i < 25; i++){
           count_arr[i] = NULL;
       }

       for(int i = 0; i < v1_size; i++){
           count_arr[path_to_v1-> at(i)-> data] = path_to_v1-> at(i);
       }
       for(int i = 0; i < v2_size; i++){
           if(count_arr[path_to_v2-> at(i)-> data] != NULL){
               return path_to_v2-> at(i);
           }
       }
       return NULL;

    }

