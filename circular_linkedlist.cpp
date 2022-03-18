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
LL_Node* create_circular_linkedlist(int[], int);
LL_Node* add_to_head_circular_linkedlist(LL_Node*, int);
LL_Node* delete_from_head_circular_linkedlist(LL_Node*);
void print_circular_linked_list(LL_Node*);
LL_Node* delete_from_circular_linkedlist(LL_Node*, int);
//------ algorithms ------

//END circular Linked List
LL_Node* create_circular_linkedlist(int arr[], int arr_size){
    LL_Node* newNode = new LL_Node(arr[0]);
    LL_Node* head = newNode;
    for (int i=1; i<arr_size; i++) {
        newNode->next = new LL_Node(arr[i]);
        newNode = newNode->next;
    }
    newNode->next = head;
    cout<<"created:\n";
    print_circular_linked_list(head);
    return head;
}

LL_Node* add_to_head_circular_linkedlist(LL_Node* head, int val){
    LL_Node* new_head = new LL_Node(val);
    new_head->next = head;
    while (head->next!=new_head->next) head = head->next;
    head->next = new_head;
    print_circular_linked_list(new_head);
    return new_head;
}

void print_circular_linked_list(LL_Node* head){
    LL_Node* node = head;
    while (node->next!=head) {
        cout<<node->data<<"->";
        node=node->next;
    }
    cout<<node->data<<"->";
    cout<<endl;
}

LL_Node* delete_from_head_circular_linkedlist(LL_Node* head){
    LL_Node* new_head = head->next;
    LL_Node* node = head;
    while (node->next != head) node = node->next;
    node->next = new_head;
    print_circular_linked_list(new_head);
    return new_head;
}

LL_Node* delete_from_circular_linkedlist(LL_Node* head, int val){
    LL_Node* node = head;
    if (head->data == val) {
        head = delete_from_head_circular_linkedlist(node);
    } else {
        while (node->next!=head) {
            if(node->next->data==val) node->next = node->next->next;
            node = node->next;
        }
    }
    print_circular_linked_list(head);
    return head;
}
//START circular Linked List