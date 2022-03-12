class BinaryTree;

//--- Binary Tree Node START
struct BinaryTree_Node{
    BinaryTree_Node* left;
    BinaryTree_Node* right;
    int data;
    BinaryTree_Node(int val){
        left = NULL;
        right = NULL;
        data = val;
    }
};
//--- Binary Tree Node END

class BinaryTree{
public:
    int idx;
    
    BinaryTree(){
        idx = -1;
    }
    
    Node* build_binary_tree(int arr[], int size){ //build tree
        idx++;
        if ((idx>=size)||(arr[idx]==-1)) return NULL;
        Node* newNode = new Node(arr[idx]);
        newNode->left = build_binary_tree(arr, size);
        newNode->right = build_binary_tree(arr, size);
        return newNode;
    }
    
    void print_preorder_binary_tree(Node* root){ //print tree preorder
        cout<<root->data<<" ";
        if(root->left!=NULL) print_preorder_binary_tree(root->left); else cout<<-1<<" ";
        if(root->right!=NULL) print_preorder_binary_tree(root->right); else cout<<-1<<" ";
    }
    
    void print_inorder_binary_tree(Node* root){ //print tree inorder
        if(root->left!=NULL) {print_inorder_binary_tree(root->left);} else {cout<<" -1 "; }
        cout<<root->data<<" ";
        if(root->right!=NULL) {print_inorder_binary_tree(root->right);} else{cout<<" -1 "; }//return;
    }
    
    void print_postorder_binary_tree(Node* root){ //print tree inorder
        if(root->left!=NULL) {print_postorder_binary_tree(root->left);} else {cout<<" -1 "; }
        if(root->right!=NULL) {print_postorder_binary_tree(root->right);} else{cout<<" -1 "; }//return;
        cout<<root->data<<" ";
    }
    
};

//Binary Tree Specific
//subtree - left subtree, right subtree
//Max nodes at level L = 2^L
//Max nodes in tree of height H = 2^H-1
//Min possible height of tree = log2(N+1)
//Min possible level of tree = log2(N)

