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

Node* deleteNode(Node* head, int ele){
    if(head == NULL) return head;

    Node* temp = head;
    Node* front = head->next;
    Node* prev = head->back;
    if(head->data == ele){
        head = front;
        head->back = prev;
        temp->back = temp->next = nullptr;
        delete temp;
        return head;
    }

    while(temp != NULL){
        if(temp->data == ele){
            if(front == NULL){
                prev->next = nullptr;
                temp->back = nullptr;
                free(temp);
                break;
            }
            prev->next = front;
            front->back = prev;
            temp->back = temp->next = nullptr;
            free(temp);
            break;
        }
        prev = temp;
        temp = front;
        front = front->next;
    }
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

    head = deleteNode(head, 8);
    printDLL(head);

    return 0;
}