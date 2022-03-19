#define n 100
// #include "stdc++.h"
using namespace std;
void print_stack(stack<int> s);

//need to comment stack when including stack header otherwise they would conflict
// class stack {
//     int *arr;
//     int s_top;
//     public:
//         stack(){
//             arr = new int[n];
//             s_top = -1;
//         }
//         void push(int val) {
//             if (s_top-1>=n) {
//                 cout<<"Exception: stack overflow\n";
//             }
//             else arr[++s_top] = val;
//         }
//         void pop() {
//             if (s_top<0) {
//                 cout<<"Exception: stack overflow\n";
//             }
//             else s_top--;
//         }
//         int top() {
//             if (s_top<0) {
//                 cout<<"Exception: stack underflow\n";
//                 return -1;
//             }
//             else return arr[s_top];
//         }
//         bool is_empty() {
//             return s_top<0;
//         }
// };

string reverse_a_sentence(string str) {
    stack<string> st;
    for (int i=0; i<str.length(); i++){
        string word = "";
        while((str[i]!=' ') && (i<str.length())) {
            word+=(str[i]); i++;
        }
        st.push(word);
    }
    string reversed_str = "";
    while (!st.empty()) {
        reversed_str += (st.top()+" ");
        st.pop();
    }
    return reversed_str;
}

stack<int> reverse_stack(stack<int> s) { //reverse without secondary stack
    stack<int> reversed_stack;
    while(!s.empty()) {
        int v = s.top();
        reversed_stack.push(v);
        s.pop();
    }
    return reversed_stack;
}

void insert_at_bottom(stack<int> &s, int ele) { //todo: pointers, recursion
    if(s.empty()) {s.push(ele); return;}
    int top_ele = s.top();
    s.pop();
    insert_at_bottom(s, ele);
    s.push(top_ele);
    print_stack(s); 
}

void print_stack(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}


