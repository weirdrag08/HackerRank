
/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
*/

    void levelOrder(Node *root) {
       queue<Node*> pending_nodes;
       pending_nodes.push(root);
       while(!pending_nodes.empty()){
           Node *front = pending_nodes.front();
           pending_nodes.pop();
           cout << front-> data << " ";
           if(front-> left != NULL){
               pending_nodes.push(front-> left);
           }
           if(front-> right != NULL){
               pending_nodes.push(front-> right);
           }
       }

    }

