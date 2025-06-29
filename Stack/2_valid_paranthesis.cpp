#include <iostream>
#include <string>
#include <stack>
#include<bits/stdc++.h>
using namespace std;
bool isValid(string s) {
    int n = s.size();
    stack<char> st;
    for(int i = 0; i < n; i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        }
        else{
            if(st.size() == 0){
                return false;
            }

            char top = st.top();
            st.pop();
            if((s[i] == ')' && top == '(') || (s[i] == '}' && top == '{') || (s[i] == ']' && top == '[')){
                continue;
            }
            else{
                return false;
            }
        }
    }
    return st.empty();
}

int main(){
    string s="()[{}()]";
    if(isValid(s)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }

    return 0;
}