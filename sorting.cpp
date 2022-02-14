#include <iostream>
using namespace std;

int search_element_index(int arr[], int val, int size);
int binary_search_element_index(int arr[], int val, int size);
void selection_sort(int arr[], int size);
void print_array(int arr[], int size);
int* swap_arr_val(int arr[], int f, int s);
void bubble_sort(int arr[], int size);

int main() {
    int arr[] = {3131,521,246,442,1513,32};
    int size = sizeof(arr)/sizeof(arr[0]);
    // int found_index = search_element_index(arr, 532, size);
    // int found_index = binary_search_element_index(arr, 532, size);
    // selection_sort(arr, size);
    bubble_sort(arr, size);
    // cout<<found_index;
    return 0;
}

//Task 1: remove size parameters from the arguments
//search array 
//(linear) O(n)
int search_element_index(int arr[], int val, int size){
    // cout<<"sizeof arr "<<sizeof(arr)<<"\n";
    int index = -1;

    for (int i=0; i < size; i++) {
        if (arr[i] == val) return i;
    }
    return index;
}

//(binary) O(logn)
int binary_search_element_index(int arr[], int val, int size){
    int f=0;
    int l=size-1;

    if (size==0) return -1;

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

//sorting 
//Task 2: return another array instead of modifying the original
//selection sort 
void selection_sort(int arr[], int size){
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

//sorting 
//bubble sort
void bubble_sort(int arr[], int size){
    for(int j=0; j<size-1; j++){
        for(int i=0; i<size-1-j; i++){
            if(arr[i]>arr[i+1]){
                swap_arr_val(arr, i, i+1);
            }
        }
    }

    print_array(arr, size);
}

int* swap_arr_val(int arr[], int f, int s){
    int temp = arr[s];
    arr[s] = arr[f];
    arr[f] = temp;
    return arr;
}

void print_array(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<'<';
    }
}