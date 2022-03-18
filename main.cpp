// #include </Library/Developer/CommandLineTools/usr/lib/clang/13.0.0/include/bits/stdc++.h>
#include "stdc++.h"
#include "utilities.cpp"
using namespace std;

//End Doubly Linkedlist Node
struct DLL_Node
{
    DLL_Node* prev;
    DLL_Node* next;
    int data;
    DLL_Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
    DLL_Node(int val, DLL_Node* prev_ptr) {
        data = val;
        next = NULL;
        prev = prev_ptr;
    }
};

//Start Doubly Linkedlist Node

//algoritgms
DLL_Node* create_doubly_linked_list(int[], int);
void print_doubly_linked_list(DLL_Node*);
void insert_at_tail(DLL_Node*, int);
//algoritgms

//main
int main() {
    int arr[] = {19, 29, 10, 824,5,17,14,534,53,1558,1699,103, 3,4, 5,3,35,333};//{23,1,646,45,2534,690,3433};//{43,5,32,2,3,65,3,4,6};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    DLL_Node* head = create_doubly_linked_list(arr, arr_size);
    insert_at_tail(head, 69);
    cout<<'\n';
    return 0;
}

DLL_Node* create_doubly_linked_list(int arr[], int arr_size) {
    DLL_Node* head = new DLL_Node(arr[0]);
    DLL_Node* new_node = head;
    for (int i = 1; i < arr_size; i++)
    {
        new_node->next = new DLL_Node(arr[i], new_node);
        new_node = new_node->next;
    }
    print_doubly_linked_list(head);
    return head;
}

void print_doubly_linked_list(DLL_Node* head){
    DLL_Node* node = head;
    cout<<"->"<<node->data;
    node = node->next;
    while (node) {
        cout<<"<->"<<node->data;
        node = node->next;
    }
    cout<<endl;
}

void insert_at_tail(DLL_Node* head, int val){
    DLL_Node* node = head;
    while (node->next) node = node->next;
    node->next = new DLL_Node(val, node);
    print_doubly_linked_list(head);
}

//Questions
//class vs structs

//ref-1 https://www.youtube.com/watch?v=j9RG18jfnRY&ab_channel=ApnaCollege
