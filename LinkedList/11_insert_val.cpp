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

Node* insertBeforeValue(Node* head, int ele, int val){
    if(head == NULL){
        return NULL;
    }

    if(head->data == val){
        Node* temp = new Node(ele, head);
        return temp;
    }

    Node* temp = head;
    while(temp->next != NULL){
        if(temp->next->data == val){
            Node* newNode = new Node(ele);
            newNode->next = temp->next;
            temp->next = newNode;
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
    vector<int> arr = {12,6,8,9};
    Node* head = convertToLL(arr);
    head = insertBeforeValue(head, 100, 9);
    
    print(head);

    return 0;
}