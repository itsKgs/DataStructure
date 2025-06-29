#include <iostream>
#include <bits\stdc++.h>
using namespace std;
//TC : O(N)
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

Node* removeTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next); //delete temp->next; 
    temp->next = nullptr;
    return head;
}

Node* removeK(Node* head, int ele){
    if(head == NULL) return head;
    if(head->data == ele){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* prev = NULL;
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == ele){
            prev->next = prev->next->next;
            free(temp);
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
    Node* head = convertToLL(arr);
    head = removeK(head, 8);
    
    print(head);

    return 0;
}