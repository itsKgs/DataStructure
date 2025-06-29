#include <iostream>
#include <stack>
// TC : O(N) + O(N) == O(2N)
// SC : O(N) 
using namespace std;
string prefixToPostfix(string s, stack<string>& st, int n){
    int i = n-1;
    while (i >= 0){ //O(N)
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            string oprand = string(1, s[i]);
            st.push(oprand); //O(1)
        }
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string temp = t1 + t2 + s[i];// O(len(t1)) + O(len(t2)) 
            st.push(temp);
        }
        i--;
    }
    return st.top();
}

int main(){
    string s = "/-AB*+DEF";
    int n = s.size();
    stack<string> st;
    cout<<prefixToPostfix(s, st, n)<<endl;

    return 0;
}