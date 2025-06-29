#include <iostream>
#include <bits/stdc++.h>
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

Node* insertTail(Node* head, int val){
    if(head == NULL) return new Node(val, head);
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* NewNode = new Node(val);
    temp->next = NewNode;
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
    vector<int> arr = {1,2,3,4};
    Node* head = convertToLL(arr);
    head = insertTail(head, 100);
    
    print(head);

    return 0;
}