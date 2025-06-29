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

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* dummyNode = new Node(-1);
    Node* current = dummyNode;
    Node* t1 = l1;
    Node* t2 = l2;
    int carry = 0;
    int sum = 0;
    while(t1 != 0 || t2 != 0){
        if(t1){
            sum = sum + t1->data;
        }
        if(t2){
            sum = sum + t2->data;
        }
        Node* newNode = new Node(sum%10);
        carry = sum/10;
        current->next = newNode;
        current = newNode;
        if(t1){
            t1 = t1->next;
        }
        if(t2){
            t2 = t2->next;
        }
        sum = carry;
    }

    if(carry){
        Node* carryNode = new Node(carry);
        current->next = carryNode;
    }
    return dummyNode->next;
}

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    vector<int> arr1 = {3, 5};
    vector<int> arr2 = {4, 5, 9, 9};
    Node* head1 = convertToLL(arr1);
    Node* head2 = convertToLL(arr2);
    head1 = addTwoNumbers(head1, head2);
    
    print(head1);

    return 0;
}