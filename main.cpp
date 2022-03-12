#include </Library/Developer/CommandLineTools/usr/lib/clang/13.0.0/include/bits/stdc++.h>
#include "utilities.cpp"
using namespace std;

//--- Linked List Node START
struct LL_Node{
    LL_Node* next;
    int data;
    LL_Node(int val){
        next = NULL;
        data = val;
    }
};
//---Linked List Node START

//------ algorithms ------
LL_Node* create_linked_list(int arr[], int size);
void print_linked_list(LL_Node*);
//------ algorithms ------

//main
int main() {
    int arr[] = {19, 29, 10, 824,5,17,14,534,53,1558,1699,103, 3,4, 5,3,35,333};//{23,1,646,45,2534,690,3433};//{43,5,32,2,3,65,3,4,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    print_linked_list(create_linked_list(arr, size));
    cout<<'\n';
    return 0;
}


//End Linked List
LL_Node* create_linked_list(int arr[], int size){
    LL_Node* newNode = new LL_Node(arr[0]);
    LL_Node* head = newNode;
    for (int i=1; i<size; i++) {
        newNode->next = new LL_Node(arr[i]);
        newNode = newNode->next;
    }
    return head;
}

void print_linked_list(LL_Node* root){
    while (root!=NULL) {
        cout<<root->data<<", ";
        root = root->next;
    }
}
//Start Linked List

//Questions
//class vs structs


//ref-1 https://www.youtube.com/watch?v=j9RG18jfnRY&ab_channel=ApnaCollege
