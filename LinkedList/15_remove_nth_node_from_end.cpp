#include <iostream>
#include <bits\stdc++.h>
using namespace std;
//TC : O(len(LL)) + O(len(LL) - n) 
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

int lengthOfLL(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp != nullptr){ 
        temp = temp->next;
        count++;
    }
    return count;
}

Node* removeK(Node* head, int k){
    if(head == NULL) return head;
    if(k == 1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int count = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        count++;
        if(count == k){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
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
    vector<int> arr = {12,6,8,9};
    int n = 2;
    Node* head = convertToLL(arr);
    head = removeK(head, lengthOfLL(head) - n + 1);
    
    print(head);

    return 0;
}