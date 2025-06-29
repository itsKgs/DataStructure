#include <iostream>
#include <stack>
#include <bits\stdc++.h>
using namespace std;
//TC : O(2N)
//SC : O(N) 
struct Node{
    public:
        int data;
        Node* next;

    Node(int data1, Node* next1 = nullptr){
        data = data1;
        next = next1;
    }
};

Node* convertToLL(vector<int> &arr){
    int n = arr.size();

    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i < n; i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

bool isPalindrome(Node *head) {
    stack<int> st;
    Node* temp = head;
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    
    temp = head;
    while(temp != NULL){
        if(temp->data != st.top()) return false;
        st.pop();
        temp = temp->next;
    }
    return true;
}

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {1,2,3,4,2};
    Node* head = convertToLL(arr);
    cout<<isPalindrome(head)<<endl;

    return 0;
}