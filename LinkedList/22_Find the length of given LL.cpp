#include <iostream>
#include <map>
#include <bits\stdc++.h>
using namespace std;
//TC : O(N * map)
//SC : O(N) 
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

int countNodesinLoop(Node *head) {
    unordered_map<Node*, int>mp;
    Node* temp = head;
    int timer = 1;
    while(temp != NULL){
        if(mp.find(temp) != mp.end()){
            int value = mp[temp];
            return timer - value;
        }
        mp[temp] = timer;
        timer++;
        temp = temp->next;
    }
    return 0;
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
    cout<<detectCycle(head)<<endl;

    return 0;
}