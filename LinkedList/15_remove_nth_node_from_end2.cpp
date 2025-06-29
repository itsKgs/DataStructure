#include <iostream>
#include <bits\stdc++.h>
using namespace std;

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
 

Node* removeK(Node* head, int k){
    Node* fast = head;
    for(int i = 0; i < k; i++) fast = fast->next;
    if(fast == NULL) return head->next;
    
    Node* slow = head;
    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }

    Node* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
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
    head = removeK(head, n);
    
    print(head);

    return 0;
}