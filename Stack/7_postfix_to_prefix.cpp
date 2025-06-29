#include <iostream>
#include <stack>
// TC : O(N) + O(N) == O(2N)
// SC : O(N) 
using namespace std;
string postfixToPrefix(string s, stack<string>& st, int n){
    int i = 0;
    while (i < n){ //O(N)
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            string oprand = string(1, s[i]);
            st.push(oprand); //O(1)
        }
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string temp = s[i] + t2 + t1;// O(len(t1)) + O(len(t2)) 
            st.push(temp);
        }
        i++;
    }
    return st.top();
}

int main(){
    string s = "AB-DE+F*/";
    int n = s.size();
    stack<string> st;
    cout<<postfixToPrefix(s, st, n)<<endl;

    return 0;
}