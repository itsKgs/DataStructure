#include <iostream>
#include <map>
#include <bits\stdc++.h>
using namespace std;
//TC : O(N/2)
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

Node *Cycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast) { 
            slow = head; 
            while (slow != fast) { 
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;;
}

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {9,9,5,9};
    Node* head = convertToLL(arr);
    head = deleteMiddle(head);
    print(head);

    return 0;
}