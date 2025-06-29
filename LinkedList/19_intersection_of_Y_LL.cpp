#include <iostream>
#include <map>
#include <bits\stdc++.h>
using namespace std;
//TC : O(N1 * map) + O(N2 * map)
//SC : O(N1) 
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

Node* intersectPoint(Node* head1, Node* head2) {
    unordered_map<Node*, int> mp;
    Node* temp = head1;
    while(temp != NULL){
        mp[temp] = 1;
        temp = temp->next;
    }
    
    temp = head2;
    while(temp != NULL){
        if(mp.find(temp) != mp.end()){
            return temp;
        }
    }
    return NULL;
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