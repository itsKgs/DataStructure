#include <iostream>
#include <bits\stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node* back;

    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertTo2DLL(vector<int> &arr){
    int n = arr.size();
    Node* head = new Node(arr[0], nullptr, nullptr);
    Node* prev = head;

    for(int i = 1; i < n; i++){
        Node* temp = new Node(arr[i], nullptr, nullptr);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void printDLL(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}



int main(){
    vector<int> arr = {2,6,8,9};
    Node* head = convertTo2DLL(arr);
    printDLL(head);

    return 0;
}