#include <iostream>
#include <stack>
#include <bits\stdc++.h>
using namespace std;
//TC : O(2N)
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

Node* reverseList(Node* head) {
    Node* temp = head;
    Node* last = NULL; 
    while(temp != NULL){
        Node* front = temp->next;
        temp->next = last;
        last = temp;
        temp = front;
    }
    return last;
}

bool isPalindrome(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* newHead = reverseList(slow->next);
    Node* first = head;
    Node* second = newHead;
    while(second != NULL){
        if(first->data != second->data){
            reverseList(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }

    reverseList(newHead);
    return true;
}

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {1,2,3,3,2,1};
    Node* head = convertToLL(arr);
    cout<<isPalindrome(head)<<endl;

    return 0;
}