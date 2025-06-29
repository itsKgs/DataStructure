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
    Node* temp = head;
    int count_0 = 0;
    int count_1 = 0;
    int count_2 = 0;
    while(temp != NULL){
        if(temp->data == 0){
            count_0++;
        }
        else if(temp->data == 1){
            count_1++;
        }
        else{
            count_2++;
        }
        temp = temp->next;
    }
    
    temp = head;
    while(temp != NULL){
        if(count_0){
            temp->data = 0;
            count_0--;
        }
        else if(count_1){
            temp->data = 1;
            count_1--;
        }
        else{
            temp->data = 2;
            count_2--;
        }
        temp = temp->next;
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
    vector<int> arr = {1,0,1,2,0,2,1};
    Node* head = convertToLL(arr);
    head = segregate(head);
    
    print(head);

    return 0;
}