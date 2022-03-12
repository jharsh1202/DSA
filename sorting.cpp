#include </Library/Developer/CommandLineTools/usr/lib/clang/13.0.0/include/bits/stdc++.h>
using namespace std;

//------ algorithms ------
//Sorting
int partition(int arr[], int f, int l);
void quicksort(int arr[], int f, int l);
void merge(int arr[], int f, int mid, int l);
void merge_sort(int arr[], int f, int l);
void insertion_sort(int arr[], int size);
void bubble_sort(int arr[], int size); //bubble sort- O(n^2)
void selection_sort(int arr[], int size); //selection sort - O(n^2)
//------ algorithms ------

//-------- SORTING END --------

int partition(int arr[], int f, int l){ //quick sort helper
    cout<<"f "<<f<<endl;
    int pivot = arr[l];
    int i = f-1;
    for (int index=f; index<l; index++) {
        if (arr[index]<pivot) {
            i++;
            swap_arr_val(arr, i, index);
        }
    }
    int pivot_index = i+1;
    swap_arr_val(arr, pivot_index, l);
    return pivot_index;
}

void quicksort(int arr[], int f, int l){  //quick sort
    if(f<l){
        int pivot_index = partition(arr, f, l);
        quicksort(arr, f, pivot_index-1);
        quicksort(arr, pivot_index+1, l);
    }
}

void merge(int arr[], int f, int mid, int l){//f, mid        mid+1, l  //merge sort helper
    int l_size = mid-f+1;
    int r_size = l-mid;
    int l_arr[l_size];
    int r_arr[r_size];
    
    for (int i=0; i<l_size; i++) {
        l_arr[i]=arr[f+i];
    }
    for (int i=0; i<r_size; i++) {
        r_arr[i] = arr[mid+1+i];
    }
    cout<<"full ";
    print_array(arr, l-f+1);
    cout<<"left ";
    print_array(l_arr, l_size);
    cout<<"right ";
    print_array(r_arr, r_size);
    
    int i=f;
    int lft=0;
    int rgt=0;
    
    while((lft<l_size)&&(rgt<r_size)){
        if (l_arr[lft]>r_arr[rgt]) {
            arr[i]=r_arr[rgt]; rgt++; i++;
        } else {
            arr[i]=l_arr[lft]; lft++; i++;
        }
    }
    
    while (lft<l_size) {
        arr[i] = l_arr[lft];
        i++; lft++;
    }
    
    while (rgt<r_size) {
        arr[i] = r_arr[rgt];
        i++; rgt++;
    }
    
}

void merge_sort(int arr[], int f, int l){ //merge sort
    print_array(arr, l-f+1);
    if (f < l) {
        int mid = (f+l)/2;
        merge_sort(arr, f, mid);
        merge_sort(arr, mid+1, l);
        merge(arr, f, mid, l);
    }
}


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


