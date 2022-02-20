#include </Library/Developer/CommandLineTools/usr/lib/clang/13.0.0/include/bits/stdc++.h>
using namespace std;
//--- Structs START -----
//Binary tree node
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){ //constructor in struct
        data = val;
        left = NULL;
        right = NULL;
    }
};
//--- Structs END -----


//Trees
class BinaryTree;

//------ recusion ------
//https://www.youtube.com/watch?v=9rt-hFcXd0M&ab_channel=ApnaCollege
//https://www.youtube.com/watch?v=VQVeAQVs1d8&ab_channel=ApnaCollege
void create_words_from_phone_keys(vector<string> keys_letter_combs, int f, int s, string res);
void print_substring_with_ascii(string str, string substring);
void print_substring(string str, string substring);
string move_all_x_to_end(string str);
string remove_duplicates(string str); //Task 5 do for any kind of string this supports only seq duplicates like "aabbccdd"
void tower_of_hanoi(int disks, int A, int B, int C); //Todo //    tower of hanoi (steps print ref-1 @13:00

string replace_pi(string str);
void print_reverse_string(string str);
string reverse_string(string str, unsigned long size, unsigned long idx);
int first_occurance_array(int arr[], int last_index, int first_index, int val);
int last_occurance_array(int arr[], int size, int val);
bool isArraySorted(int arr[], int size);
int fibonacci(int N);
int factorial(int N);
int calculate_n_power_p (int n, int p);
int add_sequence(int N);
int add_sequence(int N, int sum); //Task 3: do it without second variable
void print_sequence(int N);
void print_sequence_reverse(int N);
//------ recusion ------

//------ algorithms ------
//Sorting
void insertion_sort(int arr[], int size);
void bubble_sort(int arr[], int size); //bubble sort- O(n^2)
void selection_sort(int arr[], int size); //selection sort - O(n^2)
//Searching
int binary_search_element_index(int arr[], int val, int size); //binary search - O(logn) - needs sorted array
int search_element_index(int arr[], int val, int size); //linear search - O(n)
//------ algorithms ------

//utilties
void print_tree(Node* root); //print binary tree
void print_array(int arr[], int size); //print array
int* swap_arr_val(int arr[], int f, int s); //swap two array values

//-------- TREE END -------------- create visual notes
//1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1
class BinaryTree{
    //build tree
    //print tree
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
//Node - struct
//preorder
//subtree
//levels - starts from 0 from root, depth starts from 0 from root, height stats from 0 from leaf
//leaf - which has no child
//sibling - node with same parent
//ancestor's parent and their parent upto root

//Binary Tree Specific
//subtree - left subtree, right subtree
//Max nodes at level L = 2^L
//Max nodes in tree of height H = 2^H-1
//Min possible height of tree = log2(N+1)
//Min possible level of tree = log2(N)


//--------  TREE START --------------


//main
int main() {
//    int arr[] = {1,23,45,646,690,2534,3433};//{43,5,32,2,3,65,3,4,6};
//    int size = sizeof(arr)/sizeof(arr[0]);
    string str = "har";//"picphgtpftipipibgvjpiip";//xxaaxaabbxbcccxcddxdd
    vector<string> keys_letter_combs = {"", "./", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    create_words_from_phone_keys(keys_letter_combs, 2, 3, "");
    print_substring_with_ascii(str, ""); //Task 7 couldn't understand que and and both ref-1 @28mins
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
    cout<<'\n';
    return 0;
}


//-------- HEAP END --------------

//dynamic memory allocation, variable allocation is done with 'new' keyword, deallocation has to be done manually with 'delete' keyword
//dangling pointer - a pointer which is pointing to an empty heap, probably becuause it was deleted or freed manually. this pointer can be reused or deleted from stack
//delete a heap block at reference ptr - delete ptr[]
//to remove ptr from stack - p = NULL;

//-------- HEAP START --------------


//-------- STACK END --------------



//static memory allocation, First in Last out, every variable allocation is by default in stack
//-------- STACK START --------------

//-------- Recusion END -------------

    void create_words_from_phone_keys(vector<string> keys_letter_combs, int f, int s, string res){
//        ref-1 @32:00
    }

    void print_substring_with_ascii(string str, string substring) { //Task 6 - Save in vector instead of printing
        if(str.length()==0) {
            cout<<substring<<",";
            return;
        }
        print_substring_with_ascii(str.substr(1), substring+str[0]);
        print_substring_with_ascii(str.substr(1), substring);
    }

    void print_substring(string str, string substring) { //Task 6 - Save in vector instead of printing
        if(str.length()==0)
            {cout<<substring<<","; return;}
        print_substring(str.substr(1), substring+str[0]);
        print_substring(str.substr(1), substring);
    }

    string move_all_x_to_end(string str){//xxabxd
        if (str.length()== 1) return str;
        string next = move_all_x_to_end(str.substr(1, str.length()));
        if (str[0]=='x') return (next+str[0]); else return str[0]+next;
    }

    string remove_duplicates(string str) {
        if (str.length()<=0) return str;
        char current = str[0];
        string next = remove_duplicates(str.substr(1, str.length()));
        if (next[0]==current) return next;
        else return current+next;
    }


//tower of hanoi algo
/*
 to put all disks from A to C
if A.len == 2 {A->B; A->C; B->C}
if A.len == 1 A->C; return;
else put_n-1_f_s_l(A,C,B)
*/
//void tower_of_hanoi(int disks, int A, int B, int C){
//    if (disks==0) {cout<<A<<B<<C<<endl; return;}
//    else if (A==1) {--A; ++C; cout<<A<<B<<C<<endl; return;}
//    else if (A==2) {--A; ++B; --A; ++C; --B; ++C; return tower_of_hanoi(disks, C,B,A+1);}
//    tower_of_hanoi(--disks, A-1, B, C);
//}

string replace_pi(string str) {// "3.14cphgtpfti3.143.14bgvj3.14ip";
    string new_str;
    int first_pi_idx = (int)str.find("pi");
    if (first_pi_idx==-1) return str;
    if (first_pi_idx==0) {new_str = "3.14"+str.substr((first_pi_idx+2), str.length());}
    else{
        new_str = str.substr(0,first_pi_idx)+"3.14"+str.substr((first_pi_idx+2), str.length());}
    return replace_pi(new_str);
}

void print_reverse_string(string str){
    if (str.length()<=0) return;
    else cout<<str[str.length() - 1];
    if (str.length()-2>=0) return print_reverse_string(str.substr(0, (str.length() - 1)));
}

string reverse_string(string str, unsigned long size, unsigned long last_idx){ //Task without 3 variables
    if (last_idx<size/2) return str;
    unsigned long temp = str[last_idx];
    str[last_idx]=str[size-(unsigned long)1-last_idx];
    str[size-1-last_idx]=temp;
    return reverse_string(str, size, --last_idx);
}

int first_occurance_array(int arr[], int last_index, int first_index, int val){
    if(first_index>last_index) return -1;
    if (arr[first_index]==val) return first_index;
    return first_occurance_array(arr, last_index, ++first_index, val);
}

int last_occurance_array(int arr[], int last_index, int val){ //12, 5, 6, 3, 7
    if (last_index==-1) return -1;
    if (arr[last_index]==val) return last_index;
    return last_occurance_array(arr, --last_index, val);
}

bool isArraySorted(int arr[], int last_index) { //1,2,3,4
    if (last_index==0) return true;
    if (arr[last_index]<arr[last_index-1]) return false;
    else return isArraySorted(arr, --last_index);
}

//Task 4 print fibonaaci series
int fibonacci(int N) {
    if (N==0) return 0;
    else if (N==1) return 1;
    else return (fibonacci(N-1)+fibonacci(N-2));
}

//0, 1, 1, 2, 3, 5, 8, 13, 21

int factorial(int N) {
    if (N==0 || N==1) return 1;
    else return N*factorial(N-1);
}

int calculate_n_power_p(int n, int p){  //n^p
    if(p<=0) return 1;
    else return (n * calculate_n_power_p(n, --p));
}

int add_sequence(int N) {
    if (N==1) return N;
    else return N+add_sequence(N-1);
}

int add_sequence(int N, int sum) {
    if (N>0) return add_sequence(N-1, sum + N);
    return sum;
}

void print_sequence_reverse(int N) {
    cout<<N<<" ";
    if(N>0) print_sequence_reverse(N-1);
}

void print_sequence(int N) {
    if(N>0) print_sequence(N-1);
    cout<<N<<" ";
}


//define endpoint/breakpoint

//-------- Recusion START -----------


//-------- SORTING END --------


void insertion_sort(int arr[], int size) {
    for (int i=1; i<size; i++) {
        int idx=-1;

        for (int j=0; j<i; j++) {
            if(arr[i]<arr[j]) {
                idx = j; break;
            }
        }

        if (idx>-1)
            for(int j=i; j>idx; j--)
                swap_arr_val(arr, j, j-1);
    }
    print_array(arr, size);
}


//2 < 4 < 6 < 65 < 3 < 5 < 32 < 43

void bubble_sort(int arr[], int size){ //bubble sort - O(n^2) - swap with next element
    for(int j=0; j<size-1; j++){
        for(int i=0; i<size-1-j; i++){
            if(arr[i]>arr[i+1]){
                swap_arr_val(arr, i, i+1);
            }
        }
    }

    print_array(arr, size);
}

//Task 2: return another array instead of modifying the original

void selection_sort(int arr[], int size){ //selection sort - O(n^2) - swap smallest with first
    for(int t=0; t<size; t++) {
        int min = arr[t];
        int min_index = t;
        for(int i=t+1; i<size; i++) {
            if (arr[i]<min){
                min = arr[i];
                min_index = i;
            }
        }
        arr[min_index] = arr[t];
        arr[t] = min;
    }
    print_array(arr, size);
}

//-------- SORTING START --------

//-------- SEARCHING END --------

int binary_search_element_index(int arr[], int val, int size){ //binary search - O(logn) - needs sorted array
    int f=0;
    int l=size-1;

    while(f<=l) {
        int mid=(f+l)/2;
        if(arr[mid] == val) {
            return mid;
        } else if( arr[mid] > val ){
            l = mid-1;
        } else {
            f = f+1;
        }
    }
    return -1;
}

//Task 1: remove size parameters from the arguments
    
int search_element_index(int arr[], int val, int size){ //linear search - O(n)
    int index = -1;

    for (int i=0; i < size; i++) {
        if (arr[i] == val) return i;
    }
    return index;
}

//SEARCHING START


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
void print_tree(Node* root) {
    cout<<root->data<<',';
    cout<<root->left->data<<',';
    cout<<root->left->left->data<<',';
    cout<<root->left->right->data;
}

//-------- UTILITIES START --------






//Questions
//class vs structs


//ref-1 https://www.youtube.com/watch?v=j9RG18jfnRY&ab_channel=ApnaCollege
