#include <iostream>
#include <bits\stdc++.h>
using namespace std;
//TC : O(N)
struct Node{
    public:
        int data;
        Node* next;

    Node(int data1, Node* next1 = nullptr){
        data = data1;
        next = next1;
    }

    //Node(int data1){
    //    data = data1;
    //    next = nullptr;
    //}
};

Node* convertToLL(vector<int> &arr){
    int n = arr.size();

    Node* head = new Node(arr[0], nullptr);
    Node* mover = head;

    for(int i = 1; i < n; i++){
        Node* temp = new Node(arr[i], nullptr);
        mover->next = temp;
        mover = temp;
    }

    //Node* head = new Node(arr[0]);
    //Node* mover = head;
//
    //for(int i = 1; i < n; i++){
    //    Node* temp = new Node(arr[i]);
    //    mover->next = temp;
    //    mover = temp;
    //}
    return head;
}

int lengthOfLL(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp){ //temp != nullptr
        temp = temp->next;
        count++;
    }
    return count;
}

int main(){
    vector<int> arr = {12,6,8,9};
    Node* head = convertToLL(arr);
    cout<<head->data<<endl;

    Node* temp = head;
    while(temp){ //temp != nullptr
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<lengthOfLL(head)<<endl;

    return 0;
}