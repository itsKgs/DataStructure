#include <iostream>
#include <map>
using namespace std;

int main(){
    string s = "aabacbebebe";
    int k = 3;
    int n = s.size();
    
    int maxL = 0;
    int l = 0;
    int r = 0;
    map<char, int> mp;
    while(r < n){
        mp[s[r]]++;
        if(mp.size() > k){
            mp[s[l]]--;
            if(mp[s[l]] == 0){
                mp.erase(s[l]);
            }
            l++;
        }
        if(mp.size() <= k){
            maxL = max(maxL, r - l + 1);
        }
        r++;
    }
    cout<<maxL<<endl;

    return 0;
}