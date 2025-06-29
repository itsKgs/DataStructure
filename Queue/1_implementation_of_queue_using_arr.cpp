#include <iostream>
using namespace std;
class MyQueue {
private:
    int arr[10];
    int start;
    int end;
    int currentSize;
    int size;

public :
    MyQueue(){start=-1;end=-1;currentSize=0;size=10;}
    void push(int);
    int pop();
    int top();
    int size();
};

// Function to push an element x in a queue.
// TC: O(1)
void MyQueue::push(int x) {
    if(currentSize == size){
        cout<<"Queue OverFlow"<<endl;
        return;
    }
    
    if(currentSize == 0){
        start = 0;
        end = 0;
    }
    else{
        end = (end + 1)%size;
    }
    arr[end] = x;
    currentSize++;
}

// Function to pop an element from queue and return that element.
// TC: O(1)
int MyQueue::pop() {
    if(currentSize == 0){
        return -1;
    }
    int ele = arr[start];
    if(currentSize == 1){
        start = end = -1;
    }
    else{
        start = (start + 1)%size;
    }
    currentSize--;
    return ele;
}

//TC: O(1)
int MyQueue::top(){
    if(currentSize == 0){
        return -1;
    }
    return arr[start];
}

//TC: O(1)
int MyQueue::size(){
    return currentSize;
}

int main(){
    MyQueue q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Popped element: " << q.pop() << endl; // Outputs: 10
    cout << "Popped element: " << q.pop() << endl; // Outputs: 20

    // Push another element
    q.push(40);

    cout << "Popped element: " << q.pop() << endl; // Outputs: 30
    cout << "Popped element: " << q.pop() << endl; // Outputs: 40

    // Attempt to pop from an empty q
    cout << "Popped element: " << q.pop() << endl; // Outputs: -1 (q is empty)

    return 0;
}