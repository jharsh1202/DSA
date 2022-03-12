#include </Library/Developer/CommandLineTools/usr/lib/clang/13.0.0/include/bits/stdc++.h>
using namespace std;

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

//------ utilties ------
void print_binary_tree(BinaryTree_Node* root); //print binary tree
void print_array(int arr[], int size); //print array
int* swap_arr_val(int arr[], int f, int s); //swap two array values
//------ utilties ------


//-------- UTILITIES END --------

//swap two array value positions
int* swap_arr_val(int arr[], int f, int s){
    int temp = arr[s];
    arr[s] = arr[f];
    arr[f] = temp;
    return arr;
}

//print array
void print_array(int arr[], int size){
    for(int i=0; i<size; i++){
        if (i==size-1) cout<<arr[i]<<"\n";
        else cout<<arr[i]<<" < ";
    }
}

//print_tree
void print_binary_tree(BinaryTree_Node* root) {
    cout<<root->data<<',';
    cout<<root->left->data<<',';
    cout<<root->left->left->data<<',';
    cout<<root->left->right->data;
}

//-------- UTILITIES START --------





//---- Notes ----

//-------- HEAP END --------------
//dynamic memory allocation, variable allocation is done with 'new' keyword, deallocation has to be done manually with 'delete' keyword
//dangling pointer - a pointer which is pointing to an empty heap, probably becuause it was deleted or freed manually. this pointer can be reused or deleted from stack
//delete a heap block at reference ptr - delete ptr[]
//to remove ptr from stack - p = NULL;
//-------- HEAP START --------------


//-------- STACK END --------------



//static memory allocation, First in Last out, every variable allocation is by default in stack
//-------- STACK START --------------


//-------- TREE END -------------- create visual notes
//1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1

//Node - struct
//preorder
//subtree
//levels - starts from 0 from root, depth starts from 0 from root, height stats from 0 from leaf
//leaf - which has no child
//sibling - node with same parent
//ancestor's parent and their parent upto root

//--------  TREE START -----------






//--- Executions ----
//    LL_Node* root = create_linked_list(arr, size);
//    print_linked_list(root);
//    string str = "har";//"picphgtpftipipibgvjpiip";//xxaaxaabbxbcccxcddxdd
//    merge(arr, 0, (0+size-1)/2, size-1);
//    merge_sort(arr, 0, size-1);
//    quicksort(arr, 0, size-1);
//    print_array(arr, size);
    
//    vector<string> keys_letter_combs = {"", "./", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//    create_words_from_phone_keys(keys_letter_combs, 2, 3, "");
//    print_substring_with_ascii(str, ""); //Task 7 couldn't understand que and and both ref-1 @28mins
//    print_substring(str, "");
//    cout<<move_all_x_to_end(str);
    
//    cout<<remove_duplicates(str);
//    tower_of_hanoi(4,4,0,0); // Task 5: Implement instances of it
//    cout<<replace_pi(str);
//    print_reverse_string(str);
//    unsigned long str_size = str.length(); //.length() & .size() are only different alias
//    cout<<reverse_string(str, str_size, str_size-(unsigned long)1);
//    cout<<first_occurance_array(arr, size-1, 0, 690);
//    cout<<last_occurance_array(arr, size-1, 646);
//    cout<<isArraySorted(arr, size-1);
//    cout<<fibonacci(4);
//    cout<<factorial(6);
//    cout<<add_sequence(6);
//    cout<<calculate_n_power_p(2, 3);
//    print_sequence_reverse(10);
//    print_sequence(10);
//    insertion_sort(arr, size);
//    selection_sort(arr, size);
//    bubble_sort(arr, size);
//    insertion_sort(arr, size);
//    binary_search_element_index(arr, 3, size);
//    int preorder_tree[] = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
//    size = sizeof(preorder_tree)/sizeof(preorder_tree[0]);
//    Node* root = BinaryTree().build_binary_tree(preorder_tree, size);
//    BinaryTree().print_preorder_binary_tree(root); cout<<"\n";
//    BinaryTree().print_inorder_binary_tree(root); cout<<"\n";
//    BinaryTree().print_postorder_binary_tree(root); cout<<"\n";
