#include <iostream>
#include <stack>
//TC: O(N) + O(N)
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
            while(!st.empty() && priority(s[i]) <= priority(st.top())){ //O(N)
                ans = ans + st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }

    while(!st.empty()){
        ans = ans + st.top();
        st.pop();
    }

    return ans;
}

int main(){
    string s = "a+b*(c^d-e)";
    int n = s.size();
    string ans = "";
    stack<char> st;

    cout<<infixToPostfix(s, st, ans, n)<<endl;

    return 0;
}