#include <iostream>
#include <bits\stdc++.h>
using namespace std;
//TC : O(len(LL)) + O(len(LL) - n) 
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

Node* reverseList(Node* head) {
    stack<int> st;
    Node* temp = head;
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    
    temp = head;
    while(temp != NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {12,6,8,9};
    int n = 2;
    Node* head = convertToLL(arr);
    head = reverseList(head);
    
    print(head);

    return 0;
}