#include <iostream>
#include <map>
#include <bits\stdc++.h>
using namespace std;
//TC : O(N + N/2)
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

int getMiddle(Node* head) {
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    
    int midNode = (count/2) + 1;
    temp = head;
    while(temp != NULL){
        midNode = midNode - 1;
        if(midNode == 0) break;
        temp = temp->next;
    }
    return temp->data;
}

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {9,9,5,9, 6};
    Node* head = convertToLL(arr);
    cout<<getMiddle(head)<<endl;

    return 0;
}