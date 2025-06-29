#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class min_stack
{
private:
    stack<int> s;
    stack<int> ss;
public:
    min_stack();
    ~min_stack();
    void push(int val);
    int pop();
    int top();
    int getMin();
};

min_stack::min_stack(){

}
void min_stack::push(int val) {
    s.push(val);
    if(ss.size() == 0 || ss.top() >= val){
        ss.push(val);
    }
}

int min_stack::pop() {
    if(s.size() == 0){
        return -1;
    }

    int ans = s.top();
    if(ans == ss.top()){
        ss.top();
    }
    return ans;
}

int min_stack::top() {
    return s.top();
}

int min_stack::getMin() {
    if(s.size() == 0){
        return -1;
    }
    return ss.top();
}

min_stack::~min_stack(){

}


int main(){
    vector<int> nums = {18,19,29,15};
    

    return 0;
}