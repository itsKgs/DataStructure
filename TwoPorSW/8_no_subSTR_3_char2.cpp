#include <iostream>
#include <set>
#include<map>
using namespace std;

int main(){
    string s = "abcabc";
    int n = s.size();
    int count = 0;
    int r = 0;
    int l = 0;
    map<char, int> mp;
    while(r < n){
        mp[s[r]]++;
        if(mp.size() == 3){
            if(mp.size() == 3){
                count =  count + n - r;
                mp[s[l]]--;
                if(mp[s[l]] == 0){
                    mp.erase(s[l]);
                }
                l++;
            }
        }
        r++;
    }
    cout<<count<<endl;

    return 0;
}