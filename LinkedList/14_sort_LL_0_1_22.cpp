#include <iostream>
#include <vector>
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

Node* segregate(Node* head) {
    if(head == NULL || head->next == NULL) return head;
    
    Node* zero = new Node(-1);
    Node* zeroHead = zero;
    
    Node* one = new Node(-1);
    Node* oneHead = one;
    
    Node* two = new Node(-1);
    Node* twoHead = two;
    
    Node* temp = head;
    
    while(temp != NULL){
        if(temp->data == 0){
            zero->next = temp;
            zero = zero->next;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = one->next;
        }
        else{
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    
    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = NULL;
    
    Node* newHead = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return newHead;
}

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {1,0,1,2,0,2,1};
    Node* head = convertToLL(arr);
    head = segregate(head);
    
    print(head);

    return 0;
}