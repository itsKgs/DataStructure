#include <iostream>
#include <bits\stdc++.h>
using namespace std;
struct Node{
    public:
        int data;
        Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

int main(){
    vector<int> arr = {2,6,8,9};
    Node* y = new Node(arr[0], nullptr);
    cout<<y<<endl;
    cout<<y->data<<endl;
    cout<<y->next<<endl;

    return 0;
}