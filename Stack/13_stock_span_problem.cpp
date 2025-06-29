#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    vector<int> arr = {73,74,75,71,69,72,76,73};
    int n = arr.size();
    vector<int> v;
    stack<pair<int, int>> s;

    for(int i = 0; i < n; i++){
        if(s.size() == 0){
            v.push_back(-1);
        }
        else if(s.size() > 0 && arr[i] < s.top().first){
            v.push_back(s.top().second);
        }
        else if(s.size() > 0 && arr[i] >= s.top().first){
            while (s.size() > 0 && arr[i] >= s.top().first){
                s.pop();
            }
            if(s.size() == 0){
                v.push_back(-1); 
            }
            else{
                v.push_back(s.top().second); 
            }
        }
        s.push({arr[i], i}); 
    }

    for(int i = 0; i < n; i++){
        cout<<i - v[i]<<" ";
    }
    cout<<endl;

    return 0;
}