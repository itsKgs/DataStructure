#include <iostream>
#include <stack>
#include <bits\stdc++.h>
using namespace std;
//TC : O(3N)
//SC : O(1) 
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
    Node* temp = head;
    Node* last = NULL; 
    while(temp != NULL){
        Node* front = temp->next;
        temp->next = last;
        last = temp;
        temp = front;
    }
    return last;
}

int addhelper(Node* temp){
    if(temp == NULL){
        return 1;
    }
    
    int carry = addhelper(temp->next);
    temp->data = temp->data + carry;
    if(temp->data < 10) return 0;
    temp->data = 0;
    return 1;
}

Node* addOne(Node* head) {
    int carry = addhelper(head);
    
    if(carry == 1){
        Node* newNode = new Node(1);
        newNode->next = head;
        head = newNode;
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
    vector<int> arr = {9,9,9};
    Node* head = convertToLL(arr);
    head = addOne(head);
    print(head);

    return 0;
}