#include <iostream>
#include <map>
using namespace std;

int main(){
    string s = "aabacbebebe";
    int k = 3;
    int n = s.size();
    
    int maxL = 0;
    map<char, int> mp;
    for(int i = 0; i < n; i++){
        mp.clear();
        for(int j = i; j < n; j++){
            mp[s[j]]++;
            if(mp.size() <= k){
                maxL = max(maxL, j - i + 1);
            }
            else{
                break;
            }
        }
    }
    cout<<maxL<<endl;

    return 0;
}