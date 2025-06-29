#include <iostream>
#include <vector>
using namespace std;
//TC : O(N)
//Sc : O(26) == O(1)

int main(){
    string s = "ABAB";
    int k = 2;
    int n = s.size();

    int maxL = 0;
    int l = 0; 
    int r = 0;
    int maxF = 0;
    vector<int>hash(26, 0);
    while(r < n){
        hash[s[r] - 'A']++;
        maxF = max(maxF, hash[s[r] - 'A']);
        if((r - l + 1) - maxF > k){
            hash[s[l] - 'A']--;
            l++;
        }
        if((r - l + 1) - maxF <= k){
            maxL = max(maxL, r - l + 1);
        }
        r++;
    }
    cout<<maxL<<endl;

    return 0;
}