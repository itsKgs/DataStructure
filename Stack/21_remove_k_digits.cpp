#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
//TC : O(N) + O(k) + O(N) + O(N)
//SC :O(N) + O(N)

int main(){
    string num = "1432219";
    int k = 3;
    int n = num.size();
    stack<char> st;//O(N)

    for (int i = 0; i < n; i++) {//O(N)
        while (!st.empty() && k > 0 && (st.top() - '0' > num[i] - '0')) {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }

    while (k > 0 && !st.empty()){ //O(k)
        st.pop();
        k--;
    }

    if(st.empty()){
        cout<<"0"<<endl;
    }

    string result = ""; // O(N)
    while (!st.empty()){ // O(N)
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());         //these steps O(N)
    while (result.size() > 0 && result[0] == '0'){ // 
        result.erase(result.begin());              //
    }                                              //

    if (result.empty()) {
        cout<<"0"<<endl;
    }

    for(int i = 0; i < result.size(); i++){
        cout<<result[i];
    }
    cout<<endl;
    
    return 0;
}