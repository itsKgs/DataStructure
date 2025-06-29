#include <iostream>
#include <vector>
using namespace std;
//TC : O(N + N)*O(26)
//Sc : O(26)

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
        while((r - l + 1) - maxF > k){
            hash[s[l] - 'A']--;
            maxF = 0;
            for(int i = 0; i < 26; i++){
                maxF = max(maxF, hash[i]);
            }
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