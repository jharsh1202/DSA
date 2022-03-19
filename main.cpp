// #include </Library/Developer/CommandLineTools/usr/lib/clang/13.0.0/include/bits/stdc++.h>
#include "stdc++.h"
#include "utilities.cpp"
#include "linkedlist.cpp"
using namespace std;

//main
int main() {
    int arr[] = {6, 7, 19, 29, 824, 1558, 1699}; //{23,1,646,45,2534,690,3433};//{43,5,32,2,3,65,3,4,6};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    LL_Node* ll1 = create_linked_list(arr, arr_size);
    // ll1 = add_to_head_circular_linkedlist(ll1, 3399);
    // // cout<<ll1->next->next->next->next->next->next->next->next->next->data;
    // ll1 = delete_from_head_circular_linkedlist(ll1);
    // ll1 = delete_from_circular_linkedlist(ll1, 29);
    // ll1 = delete_from_circular_linkedlist(ll1, 3399);
    // ll1 = delete_from_circular_linkedlist(ll1, 824);
    ll1 = put_even_before_odd(ll1);
    cout<<'\n';
    return 0;
}

//Questions
//class vs structs

//ref-1 https://www.youtube.com/watch?v=j9RG18jfnRY&ab_channel=ApnaCollege
