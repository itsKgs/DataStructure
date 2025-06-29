#include <iostream>
#include <bits\stdc++.h>
using namespace std;
//TC : O(1)
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

Node* insertHead(Node* head, int val){
    //Node* temp = new Node(val, head);
    //return temp;
    return new Node(val, head);
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
    Node* head = convertToLL(arr);
    //head = insertHead(head, 100);
    head = new Node(100, head);
    
    print(head);

    return 0;
}