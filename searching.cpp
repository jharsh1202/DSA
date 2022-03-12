//------ algorithms ------
//Searching
int binary_search_element_index(int arr[], int val, int size); //binary search - O(logn) - needs sorted array
int search_element_index(int arr[], int val, int size); //linear search - O(n)
//------ algorithms ------

//-------- SEARCHING END --------

int binary_search_element_index(int arr[], int val, int size){ //binary search - O(logn) - needs sorted array
    int f=0;
    int l=size-1;

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

//Task 1: remove size parameters from the arguments
    
int search_element_index(int arr[], int val, int size){ //linear search - O(n)
    int index = -1;

    for (int i=0; i < size; i++) {
        if (arr[i] == val) return i;
    }
    return index;
}

//SEARCHING START
