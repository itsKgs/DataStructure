#include <iostream>
#include <set>
using namespace std;

int main(){
    string s = "abab";
    set<string> st;
    for(int i = 0; i < s.length(); i++){    
        string str = "";
        for(int j = i; j < s.length(); j++){  
            str = str + s[j];
            st.insert(str);
        }
    }
    cout<<st.size() + 1<<endl;

    return 0;
}