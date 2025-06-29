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

Node* deleteMid(Node* head) {
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    int n = 0;
    while(temp != NULL){
        n++;
        temp = temp->next;
    }
    
    temp = head;
    int res = n/2;
    while(temp != NULL){
        res--;
        if(res == 0){
            Node* middle = temp->next;
            temp->next = temp->next->next;
            delete middle;
            break;
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
    vector<int> arr = {9,9,5,9, 6};
    Node* head = convertToLL(arr);
    head = deleteMid(head);
    print(head);

    return 0;
}