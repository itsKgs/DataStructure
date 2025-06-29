#include <iostream>
#include <vector>
#include <bits/stdc++.h>
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

Node* oddEvenList(Node* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = head->next;

    while(even != NULL && even->next != NULL){
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
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
    vector<int> arr1 = {1, 3, 4, 2, 5, 6};
    //vector<int> arr2 = {4, 5, 9, 9};
    Node* head1 = convertToLL(arr1);
    //Node* head2 = convertToLL(arr2);
    head1 = oddEvenList(head1);
    
    print(head1);

    return 0;
}