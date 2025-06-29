#include <iostream>
#include <map>
#include <bits\stdc++.h>
using namespace std;
//TC : O(N1 + 2*N2)
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

int findLength(Node* head){
    if(head == NULL) return 0;
    Node* temp = head;
    int l = 0;
    while(temp != NULL){
        l++;
        temp = temp->next;
    }
    return l;
}

Node* collisionPoint(Node* temp1, Node* temp2, int d){
    while(d){
        d--;
        temp2 = temp2->next;
    }
    
    while(temp1 != temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1;
}

Node* intersectPoint(Node* head1, Node* head2) {
    int N1 = findLength(head1);
    int N2 = findLength(head2);
    if(N1 < N2){
        return collisionPoint(head1, head2, N2 - N1);
    }
    else{
        return collisionPoint(head2, head1, N1 - N2);
    }
}

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){ //Don't run the code
    vector<int> arr = {9,9,9,9};
    Node* head = convertToLL(arr);
    head = addOne(head);
    print(head);

    return 0;
}