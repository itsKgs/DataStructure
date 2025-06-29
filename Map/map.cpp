#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
using namespace std;

int main(){
    map<int, string> mp{{1,"abc"},{2,"bcd"}};
    mp[5] = "cde";
    mp[4] = "efg";
    mp[6] = "hij";
    mp.insert({3,"ijk"});

    cout<<".find()"<<endl;
    map<int, string>:: iterator it;
    it = mp.find(6);

    if(it == mp.end()){
        cout<<"No Value"<<endl;
    }
    else{
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }

    cout<<"Erase"<<endl;
    mp.erase(6);
    if(mp.find(7) != mp.end()){
        mp.erase(it);
    }

    for(auto &st : mp){
        cout<<st.first<<" "<<st.second<<endl;
    }

    cout<<mp.size()<<endl;

    return 0;
}