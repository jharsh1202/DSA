// #include </Library/Developer/CommandLineTools/usr/lib/clang/13.0.0/include/bits/stdc++.h>
#include "stdc++.h"
#include "utilities.cpp"
using namespace std;

//todo add at specific place 

//--- Linked List Node START
struct LL_Node{
    LL_Node* next;
    int data;
    LL_Node(int val){
        next = NULL;
        data = val;
    }
    LL_Node(int val, LL_Node* next_node){
        next = next_node;
        data = val;
    }
};
//---Linked List Node START

//------ algorithms ------
LL_Node* create_linked_list(int[], int);
void print_linked_list(LL_Node*);
void add_node_at_tail(LL_Node*, int);
void add_node_at_head(LL_Node*, int);
void delete_a_value(LL_Node*, int, bool);
LL_Node* reverse_linked_list(LL_Node*);
LL_Node* reverse_linked_list_easy(LL_Node*);
LL_Node* reverse_linked_list_recursive(LL_Node*);
LL_Node* reverse_k_linked_list(LL_Node*);
LL_Node* reverse_k_linked_list(LL_Node*, int);
//------ algorithms ------

//main
int main() {
    int arr[] = {19, 29, 10, 824,5,17,14,534,53,1558,1699,103, 3,4, 5,3,35,333};//{23,1,646,45,2534,690,3433};//{43,5,32,2,3,65,3,4,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    LL_Node* head = create_linked_list(arr, size);
    add_node_at_tail(head, 999);
    add_node_at_head(head, 00);
    delete_a_value(head, 03, true);
    cout<<"modified:\n";
    print_linked_list(head);
    LL_Node* new_head  = reverse_linked_list(head);
    new_head  = reverse_linked_list_easy(new_head);
    new_head = reverse_k_linked_list(new_head, 2);
    // new_head = reverse_linked_list_recursive(new_head);
    print_linked_list(new_head);
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
    cout<<"created:\n";
    print_linked_list(head);
    return head;
}

void print_linked_list(LL_Node* node){
    cout<<"HEAD";
    while (node!=NULL) {
        cout<<"->"<<node->data;
        node = node->next;
    } 
    cout<<"->NULL"<<endl;
}

void add_node_at_tail(LL_Node* head, int value){
    LL_Node* last_node = head;
    while (last_node->next!=NULL) {
        last_node=last_node->next;
    }
    last_node->next = new LL_Node(value);
    print_linked_list(head);
}

void add_node_at_head(LL_Node* head, int value){
    LL_Node* first_node = head;
    head = new LL_Node(value, first_node);
    print_linked_list(head);
}

void delete_a_value(LL_Node* head, int value, bool delete_all){ 
    LL_Node* node = head;
    LL_Node* prev_node = head;
    while (node!=NULL){
        if (node->data==value) {
            prev_node->next=node->next;
            if (delete_all == false) break;
        }
        prev_node = node;
        node=node->next;
    }
    print_linked_list(head);
}

LL_Node* reverse_linked_list(LL_Node* head){
    LL_Node* curr_add = head;
    LL_Node* prev_add = NULL;
    LL_Node* next_add;
    while (curr_add!=NULL) {
        next_add = curr_add->next;
        curr_add->next=prev_add;
        prev_add=curr_add;
        curr_add=next_add;
    }
    cout<<"reveresed:\n";
    print_linked_list(prev_add);
    return prev_add;
}

LL_Node* reverse_linked_list_easy(LL_Node* head){ //do it recursive way without recursion
    LL_Node* curr_add = head;
    LL_Node* temp_next = NULL;
    LL_Node* prev_add=NULL;

    while(curr_add!=NULL){
        temp_next=curr_add->next;
        curr_add->next=prev_add;
        prev_add=curr_add;
        curr_add=temp_next;
    }

    cout<<"reveresed easy:\n";
    print_linked_list(prev_add);
    return prev_add;
}

LL_Node* reverse_linked_list_recursive(LL_Node* curr_add){
    if ((curr_add==NULL)||(curr_add->next==NULL)) return curr_add;
    LL_Node* newNode = reverse_linked_list_recursive(curr_add->next);
    curr_add->next->next = curr_add;
    curr_add->next = NULL;
    return newNode;
}

LL_Node* reverse_k_linked_list(LL_Node* head, int k){
    LL_Node* curr_ptr = head;
    LL_Node* prev_ptr = NULL;
    LL_Node* next_ptr;
    int count=1;
    while ((curr_ptr!=NULL)&&(count<=k)) {
        next_ptr=curr_ptr->next;
        curr_ptr->next=prev_ptr;
        prev_ptr=curr_ptr;
        curr_ptr=next_ptr;
        count++;
    }
    if (next_ptr!=NULL) head->next=reverse_k_linked_list(next_ptr, k);
    return prev_ptr;
}
//Start Linked List

//Questions
//class vs structs


//ref-1 https://www.youtube.com/watch?v=j9RG18jfnRY&ab_channel=ApnaCollege
