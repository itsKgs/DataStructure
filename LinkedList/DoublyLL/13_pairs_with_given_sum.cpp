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
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node* findTail(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    return tail;
}

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target){
    Node* left = head;
    Node* right = findTail(head);
    vector<pair<int, int>> ds;
    while(left->data < right->data){
        int sum = left->data + right->data;
        if(sum == target){
            ds.push_back({left->data, right->data});
            left = left->next;
            right = right->back;
        }
        else if(sum < target){
            left = left->next;
        }
        else{
            right = right->back;
        }
    }
    return ds;
}

void printDLL(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}


int main(){
    vector<int> arr = {2,3,6,8,9,0,4,4,5,3};
    int target = 8;
    Node* head = convertTo2DLL(arr);
    vector<pair<int, int>> result = findPairsWithGivenSum(head, target);
    
    for (auto &p : result) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }

    return 0;
}