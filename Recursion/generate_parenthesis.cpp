#include <iostream> 
#include <string> 
#include <vector> 
using namespace std;
void generateParnthesis(vector<string>& ans, int open, string current, int close, int n){
    if(current.length() == 2*n){
        ans.push_back(current);
        return;
    }
    if(open < n){
        generateParnthesis(ans, open + 1, current + '(', close, n);
    }
    if(close < open){
        generateParnthesis(ans, open, current + ')', close + 1, n);
    }
}

vector<string> f(int n){;
    vector<string> ans;
    generateParnthesis(ans, 0, "", 0, n);
    return ans;
}

int main(){
    int n = 3;
    vector<string> ans = f(n);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}