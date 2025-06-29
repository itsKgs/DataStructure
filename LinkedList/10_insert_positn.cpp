#include <iostream>
#include <bits\stdc++.h>
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

Node* insertPositon(Node* head, int ele, int k){
    if(head == NULL){
        if(k == 1){
            Node* temp = new Node(ele);
            return temp;
        }
        else{
            return NULL;
        }
    }
    if(k == 1){
        Node* temp = new Node(ele, head);
        return temp;
    }

    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count++;
        if(count == k-1){
            Node* newNode = new Node(ele);
            newNode->next = temp->next;
            temp->next = newNode;
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
    vector<int> arr = {12,6,8,9};
    Node* head = convertToLL(arr);
    head = insertPositon(head, 100, 1   );
    
    print(head);

    return 0;
}