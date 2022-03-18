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
int find_ll_size(LL_Node*);
void delete_a_value(LL_Node*, int, bool);
LL_Node* reverse_linked_list(LL_Node*);
LL_Node* reverse_linked_list_easy(LL_Node*);
LL_Node* reverse_linked_list_recursive(LL_Node*);
LL_Node* reverse_k_linked_list(LL_Node*);
LL_Node* reverse_k_linked_list(LL_Node*, int);
LL_Node* find_intersection(LL_Node*, LL_Node*);
LL_Node* merge_sorted(LL_Node* , LL_Node*);
bool detect_cycle(LL_Node*); //floyd's cycle detection, hare and tortoise algorithm //write proof
//------ algorithms ------



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

bool detect_cycle(LL_Node* head){
    LL_Node* hare = head;
    LL_Node* tortoise = head;
    bool is_cycle = false;
    while ((hare->next->next)) 
    {
        tortoise = tortoise->next;
        hare = tortoise->next->next;
        if (tortoise==hare) { is_cycle = true; break;}
    }
    return is_cycle;
}

LL_Node* put_last_k_elements_to_front(LL_Node* head, int k){ //is_for_all removes all apearing values in dll
    LL_Node* node = head;
    int ll_size=0;
    while (node) {
        ll_size++;
        node=node->next;
    }
    if (ll_size<=k) return head;
    node=head;
    for (int i = 0; i <ll_size-k-1; i++) node = node -> next;
    LL_Node* k_element = node->next;
    node->next = NULL;
    LL_Node* new_head = k_element;
    while (k_element->next) k_element=k_element->next;
    k_element->next=head;
    print_linked_list(new_head);
    return new_head;
}

LL_Node* find_intersection(LL_Node* head1, LL_Node* head2){
    LL_Node* node1 = head1;
    LL_Node* node2 = head2;
    int ll1 = find_ll_size(node1);
    int ll2 = find_ll_size(node2);
    // cout<<" "<<ll1<<" "<<ll2<<endl;
    if (ll1 > ll2) {
        while (ll2!=ll1) {
            node1=node1->next;
            ll1--;
        }
    } else {
        while (ll2!=ll1) {
            node2=node2->next;
            ll2--;
        }
    }

    // cout<<node1->data;
    // cout<<" "<<node2->data<<endl;

    while((node1) && (node2)){
        if (node1==node2) {
            cout<<node1->data;
            return node1;
        }
        if (node1->next!=NULL || node2->next!=NULL) {
            node1=node1->next;
            node2=node2->next;
        } else {
            break;
        }
    }
    return node1;
}

int find_ll_size(LL_Node* head){
    LL_Node* node = head;
    int ll_size=0;
    while (node) {
        ll_size++;
        node=node->next;
    }
    return ll_size;
}

LL_Node* merge_sorted(LL_Node* head1, LL_Node* head2){
    LL_Node* node1 = head1;
    LL_Node* node2 = head2;
    LL_Node* sorted = NULL;
    if ((head1->data)<(head2->data)) {sorted = head1; node1=node1->next;} 
    else  {sorted = head2; node2=node2->next;}

    while (node1 && node2) {
        int val1 = node1->data;
        int val2 = node2->data;
        if (val2<val1) {
            sorted->next = node2;
            node2 = node2->next;
        } else {
            sorted->next = node1;
            node1 = node1->next;
        }
        sorted = sorted->next;
    }
    while (node1) {
        sorted->next = node1;
        node1 = node1->next;
        sorted = sorted->next;
    }

    while (node2) {
        sorted->next = node1;
        node2 = node2->next;
        sorted = sorted->next;
    }
    
    
    if ((head1->data)<(head2->data)) return head1;
    else return head2;
}
//Start Linked List


//intersecting linkedlist 
// int arr[] = {19, 29, 10, 824, 55, 5, 17, 14, 534, 53, 1558, 1699, 103, 3, 4, 5};//{23,1,646,45,2534,690,3433};//{43,5,32,2,3,65,3,4,6};
// int arr2[] = {103, 3, 4, 5, 3, 55};//{23,1,646,45,2534,690,3433};//{43,5,32,2,3,65,3,4,6};
// int arr_size = sizeof(arr)/sizeof(arr[0]);
// int arr_size2 = sizeof(arr2)/sizeof(arr2[0]);
// LL_Node* head1 = create_linked_list(arr, arr_size);
// LL_Node* head2 = create_linked_list(arr2, arr_size2);
// head2->next->next->next->next->next = head1->next->next->next->next;
// // print_linked_list(head1);
// // print_linked_list(head2);
// print_linked_list(head1); print_linked_list(head2);
// LL_Node* intersection = find_intersection(head1, head2);


//arr1 = [1, 5, 6, 9, 13, 15, 17]
//arr2 = [6, 11, 14, 55, 78, 80, 90]
//comp(arr1,arr2)
//arrS = [1, 5, ]