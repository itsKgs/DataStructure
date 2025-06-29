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


int main(){
    vector<int> arr = {2,6,8,9};
    Node* y = new Node(arr[0], nullptr, nullptr);
    cout<<y<<endl;
    cout<<y->data<<endl;
    cout<<y->next<<endl;
    cout<<y->back<<endl;

    return 0;
}