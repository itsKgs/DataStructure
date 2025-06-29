#include <iostream>
using namespace std;
// TC : O(N^2)
// SC : O(256)
int main(){
    string s = "abcabcbb";
    int n = s.size();

    int maxL = 0;
    int L = 0;
    for(int i = 0; i < n; i++){//O(N)
        int hash[256] = {0};
        for(int j = i; j < n; j++){ //O(N)
            if(hash[s[j]] == 1){
                break;
            }
            L = j - i + 1;
            maxL = max(maxL, L);
            hash[s[j]] = 1;
        }
    }
    cout<<maxL<<endl;

    return 0;
}