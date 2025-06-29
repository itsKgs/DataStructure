#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
    int n;
    cin>>n;

    unordered_map<string, int> mp;

    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        mp[s]++;
    }

    for(auto &pr : mp){
        cout<<pr.first<<" "<<pr.second<<endl;
    }

    int q;
    cin>>q;

    while(q--){
        string t;
        cin>>t;
        cout<<mp[t]<<endl;
    }

    return 0;
}