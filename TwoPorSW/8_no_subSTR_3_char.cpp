#include <iostream>
#include <set>
using namespace std;

int main(){
    string s = "abcabc";
    int n = s.size();
    
    int count = 0;
    for(int i = 0; i < n; i++){
        set<char> st;
        for(int j = i; j < n; j++){
            st.insert(s[j]);
            if(st.size() >= 3){
                count = count + 1; 
            }
        }
    }
    cout<<count<<endl;

    return 0;
}
