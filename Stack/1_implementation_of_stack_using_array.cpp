#include <iostream>
using namespace std;


class MyStack{
    private:
        int arr[1000];
        int top;
    public:
        MyStack(){top=-1;}
        int pop();
        void push(int);
        int top();
        int size();
};
//TC = O(1)
//SC = O(arr[size])
void MyStack::push(int x) {
    top = top + 1;
    arr[top] = x;
}

//TC = O(1)
//SC = O(arr[size])
// Function to remove an item from top of the stack.
int MyStack::pop() {
    if(top == -1){
        return -1;
    }
    int ans = arr[top];
    pop();
    top--;
    return ans;
}

//TC = O(1)
//SC = O(arr[size])
int MyStack::top(){
    if(top == -1){
        return -1;
    }
    return arr[top];
}

//TC = O(1)
//SC = O(arr[size])
int MyStack::size(){
    return top + 1;
}

int main(){
    MyStack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Popped element: " << stack.pop() << endl; // Outputs: 30
    cout << "Popped element: " << stack.pop() << endl; // Outputs: 20

    // Push another element
    stack.push(40);

    cout << "Popped element: " << stack.pop() << endl; // Outputs: 40
    cout << "Popped element: " << stack.pop() << endl; // Outputs: 10

    // Attempt to pop from an empty stack
    cout << "Popped element: " << stack.pop() << endl; // Outputs: -1 (stack is empty)

    return 0;
}