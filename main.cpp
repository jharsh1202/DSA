// #include </Library/Developer/CommandLineTools/usr/lib/clang/13.0.0/include/bits/stdc++.h>
#include "stdc++.h"
#include "utilities.cpp"
#include "linkedlist.cpp"
using namespace std;

//main
int main() {
    int arr[] = {6, 7, 19, 29, 824, 1558, 1699};//{23,1,646,45,2534,690,3433};//{43,5,32,2,3,65,3,4,6};
    int arr2[] = {3, 4, 55, 59};//{23,1,646,45,2534,690,3433};//{43,5,32,2,3,65,3,4,6};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int arr_size2 = sizeof(arr2)/sizeof(arr2[0]);
    LL_Node* ll1 = create_linked_list(arr, arr_size);
    LL_Node* ll2 = create_linked_list(arr2, arr_size2);
    LL_Node* sorted_head = merge_sorted(ll1, ll2);
    print_linked_list(sorted_head);
    cout<<'\n';
    return 0;
}

//Questions
//class vs structs

//ref-1 https://www.youtube.com/watch?v=j9RG18jfnRY&ab_channel=ApnaCollege
