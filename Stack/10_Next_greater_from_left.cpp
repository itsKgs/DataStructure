#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    vector<int> arr = {100,80,60,70,60,75,85};
    int n = arr.size();
    vector<int> v;
    stack<int> s;

    for(int i = 0; i < n; i++){
        if(s.size() == 0){
            v.push_back(-1);
        }
        else if(s.size() > 0 && s.top() > arr[i]){
            v.push_back(s.top());
        }
        else if(s.size() > 0 && s.top() <= arr[i]){
            while(s.size() > 0 && s.top() <= arr[i]){
                s.pop();
            }
            if(s.size() == 0){
                v.push_back(-1);
            }
            else{
                v.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }

    //cout<<v.size()<<endl;
    //reverse(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}