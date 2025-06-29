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

Node* convertTo2DLL(vector<int> &arr){
    int n = arr.size();
    Node* head = new Node(arr[0], nullptr, nullptr);
    Node* prev = head;

    for(int i = 1; i < n; i++){
        Node* temp = new Node(arr[i], nullptr, nullptr);
        prev->next = temp;
        temp->back = prev;
        prev = temp;
    }
    return head;
}

Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* prev = head;
    head = head->next;

    head->back = nullptr; //making previous as null pointer so there memory become empty
    delete prev;
    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    Node* prev = temp->back;
    prev->next = nullptr;
    temp->back = nullptr; 
    delete temp;
    return head;
}

Node* deletePosition(Node* head, int k){
    if(head == NULL) return NULL;

    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count++;
        if(count == k){
            break;
        }
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;

    if(prev == NULL && front == NULL){
        delete temp;
        return NULL;
    }
    else if(prev == NULL){
        return deleteHead(head);
    }
    else if(front == NULL){
        return deleteTail(head);
    }
    prev->next = front;
    front->back = prev;
    temp->next = NULL;
    temp->back = NULL;

    return head;
}

void printDLL(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    vector<int> arr = {2,4,6,8};
    Node* head = convertTo2DLL(arr);

    head = deletePosition(head, 0);
    printDLL(head);

    return 0;
}