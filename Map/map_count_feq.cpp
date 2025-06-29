#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <map>
using namespace std;

int main(){
    int n;
    cin>>n;

    map<char, int> mp;
    char s;
    for(int i = 0; i < n; i++){

        cin>>s;
        mp[s]++;
    }

    for(auto &pr : mp){
        if(pr.first == 'a'){
            cout<<pr.first<<" "<<pr.second<<endl;
        }
    }
    cout<<mp['a']<<endl;

    return 0;
}