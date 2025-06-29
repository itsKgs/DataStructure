#include <iostream>
#include <stack>
#include <bits/stdc++.h>
//TC: O(N/2) + O(N/2) + O(N) + O(N) == O(3N)
//SC: O(N) + O(N)
using namespace std;
int priority(char s){
    if(s == '^'){
        return 3;
    }
    else if(s == '*' || s == '/'){
        return 2;
    }
    else if(s == '+' || s == '-'){
        return 1;
    }

    return -1;
}

string infixToPostfix(string s, stack<char>& st, string ans, int n){
    int i = 0;
    while (i < n){ //O(N)
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            ans = ans + s[i];
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){ //O(N)
                ans = ans + st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            if(s[i] == '^'){
                while(!st.empty() && priority(s[i]) <= priority(st.top())){ //O(N)
                    ans = ans + st.top();
                    st.pop();
                }
            }
            else{
                while(!st.empty() && priority(s[i]) < priority(st.top())){ //O(N)
                ans = ans + st.top();
                st.pop();
                } 
            }
            st.push(s[i]); 
        }
        i++;
    }

    while(!st.empty()){
        ans = ans + st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end()); //O(N/2)
    return ans;
}

int main(){
    string s = "(A+B)*C-D+F";
    int n = s.size();
    reverse(s.begin(), s.end()); //O(N/2)
    cout<<"it's : "<<s<<endl;
    for(int i = 0; i < n; i++){
        if(s[i] == ')'){
            s[i] = '(';
        }
        else if(s[i] == '('){
            s[i] = ')';
        }
    }
    cout<<"it's : "<<s<<endl;
    string ans = "";
    stack<char> st;

    cout<<infixToPostfix(s, st, ans, n)<<endl;

    return 0;
}