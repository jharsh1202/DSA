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
DLL_Node* insert_at_head(DLL_Node* , int);
DLL_Node* delete_an_element(DLL_Node* , int, bool);
DLL_Node* put_last_k_elements_to_front(DLL_Node*, int);
//algoritgms

//End Doubly Linked List
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

DLL_Node* insert_at_head(DLL_Node* head, int val){
    DLL_Node* new_head = new DLL_Node(val);
    new_head->next = head;
    if (head) head->prev = new_head;
    print_doubly_linked_list(new_head);
    return new_head;
}

DLL_Node* delete_an_element(DLL_Node* head, int val, bool is_for_all){ //is_for_all removes all apearing values in dll
    DLL_Node* node = head;
    while (node)
    {
        if (node->data==val)
        {
            if (node->prev) node->prev->next=node->next; else {head=head->next; head->prev = NULL;}
            if (node->next) node->next->prev=node->prev;
            if (is_for_all == false) break;
        }
        node = node->next;
    }
    print_doubly_linked_list(head);
    return head;
}
//Start Doubly Linked List