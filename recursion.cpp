//------ recusion ------
//https://www.youtube.com/watch?v=9rt-hFcXd0M&ab_channel=ApnaCollege
//https://www.youtube.com/watch?v=VQVeAQVs1d8&ab_channel=ApnaCollege
void create_words_from_phone_keys(vector<string> keys_letter_combs, int f, int s, string res);
void print_substring_with_ascii(string str, string substring);
void print_substring(string str, string substring);
string move_all_x_to_end(string str);
string remove_duplicates(string str); //Task 5 do for any kind of string this supports only seq duplicates like "aabbccdd"
void tower_of_hanoi(int disks, int A, int B, int C); //Todo //    tower of hanoi (steps print ref-1 @13:00

string replace_pi(string str);
void print_reverse_string(string str);
string reverse_string(string str, unsigned long size, unsigned long idx);
int first_occurance_array(int arr[], int last_index, int first_index, int val);
int last_occurance_array(int arr[], int size, int val);
bool isArraySorted(int arr[], int size);
int fibonacci(int N);
int factorial(int N);
int calculate_n_power_p (int n, int p);
int add_sequence(int N);
int add_sequence(int N, int sum); //Task 3: do it without second variable
void print_sequence(int N);
void print_sequence_reverse(int N);
//------ recusion ------


//-------- Recusion END -------------

    void create_words_from_phone_keys(vector<string> keys_letter_combs, int f, int s, string res){
//        ref-1 @32:00
    }

    void print_substring_with_ascii(string str, string substring) { //Task 6 - Save in vector instead of printing
        if(str.length()==0) {
            cout<<substring<<",";
            return;
        }
        print_substring_with_ascii(str.substr(1), substring+str[0]);
        print_substring_with_ascii(str.substr(1), substring);
    }

    void print_substring(string str, string substring) { //Task 6 - Save in vector instead of printing
        if(str.length()==0)
            {cout<<substring<<","; return;}
        print_substring(str.substr(1), substring+str[0]);
        print_substring(str.substr(1), substring);
    }

    string move_all_x_to_end(string str){//xxabxd
        if (str.length()== 1) return str;
        string next = move_all_x_to_end(str.substr(1, str.length()));
        if (str[0]=='x') return (next+str[0]); else return str[0]+next;
    }

    string remove_duplicates(string str) {
        if (str.length()<=0) return str;
        char current = str[0];
        string next = remove_duplicates(str.substr(1, str.length()));
        if (next[0]==current) return next;
        else return current+next;
    }


//tower of hanoi algo
/*
 to put all disks from A to C
if A.len == 2 {A->B; A->C; B->C}
if A.len == 1 A->C; return;
else put_n-1_f_s_l(A,C,B)
*/
//void tower_of_hanoi(int disks, int A, int B, int C){
//    if (disks==0) {cout<<A<<B<<C<<endl; return;}
//    else if (A==1) {--A; ++C; cout<<A<<B<<C<<endl; return;}
//    else if (A==2) {--A; ++B; --A; ++C; --B; ++C; return tower_of_hanoi(disks, C,B,A+1);}
//    tower_of_hanoi(--disks, A-1, B, C);
//}

string replace_pi(string str) {// "3.14cphgtpfti3.143.14bgvj3.14ip";
    string new_str;
    int first_pi_idx = (int)str.find("pi");
    if (first_pi_idx==-1) return str;
    if (first_pi_idx==0) {new_str = "3.14"+str.substr((first_pi_idx+2), str.length());}
    else{
        new_str = str.substr(0,first_pi_idx)+"3.14"+str.substr((first_pi_idx+2), str.length());}
    return replace_pi(new_str);
}

void print_reverse_string(string str){
    if (str.length()<=0) return;
    else cout<<str[str.length() - 1];
    if (str.length()-2>=0) return print_reverse_string(str.substr(0, (str.length() - 1)));
}

string reverse_string(string str, unsigned long size, unsigned long last_idx){ //Task without 3 variables
    if (last_idx<size/2) return str;
    unsigned long temp = str[last_idx];
    str[last_idx]=str[size-(unsigned long)1-last_idx];
    str[size-1-last_idx]=temp;
    return reverse_string(str, size, --last_idx);
}

int first_occurance_array(int arr[], int last_index, int first_index, int val){
    if(first_index>last_index) return -1;
    if (arr[first_index]==val) return first_index;
    return first_occurance_array(arr, last_index, ++first_index, val);
}

int last_occurance_array(int arr[], int last_index, int val){ //12, 5, 6, 3, 7
    if (last_index==-1) return -1;
    if (arr[last_index]==val) return last_index;
    return last_occurance_array(arr, --last_index, val);
}

bool isArraySorted(int arr[], int last_index) { //1,2,3,4
    if (last_index==0) return true;
    if (arr[last_index]<arr[last_index-1]) return false;
    else return isArraySorted(arr, --last_index);
}

//Task 4 print fibonaaci series
int fibonacci(int N) {
    if (N==0) return 0;
    else if (N==1) return 1;
    else return (fibonacci(N-1)+fibonacci(N-2));
}

//0, 1, 1, 2, 3, 5, 8, 13, 21

int factorial(int N) {
    if (N==0 || N==1) return 1;
    else return N*factorial(N-1);
}

int calculate_n_power_p(int n, int p){  //n^p
    if(p<=0) return 1;
    else return (n * calculate_n_power_p(n, --p));
}

int add_sequence(int N) {
    if (N==1) return N;
    else return N+add_sequence(N-1);
}

int add_sequence(int N, int sum) {
    if (N>0) return add_sequence(N-1, sum + N);
    return sum;
}

void print_sequence_reverse(int N) {
    cout<<N<<" ";
    if(N>0) print_sequence_reverse(N-1);
}

void print_sequence(int N) {
    if(N>0) print_sequence(N-1);
    cout<<N<<" ";
}


//define endpoint/breakpoint

//-------- Recusion START -----------

