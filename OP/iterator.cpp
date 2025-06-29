#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    vector<int> vec = {1,2,3,4,5};

    for(int i = 0; i < vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;

    vector<int>:: iterator it;
    for(it = vec.begin(); it != vec.end(); ++it){
        cout<<(*it)<<" ";
    }
    cout<<endl;

    for(int value : vec){ //values are being copy here from vec that's why there is no change after value++ in value
        value++;
        cout<<value<<" ";
    }
    cout<<endl;

    for(int &value : vec){ //Here value store the actual value of vec and after doing value++ it chnged
        value++;
        cout<<value<<" ";
    }
    cout<<endl;

    cout<<"Using auto"<<endl;

    for(auto &value : vec){ 
        value++;
        cout<<value<<" ";
    }
    cout<<endl;

    vector<pair<int, int>> v_p = {{1,2},{2,3},{3,4},{4,5}};
    vector<pair<int, int>>:: iterator itt;

    for(itt = v_p.begin(); itt != v_p.end(); ++itt){
        cout<<(*itt).first<<" "<<(*itt).second<<endl;
    }

    cout<<"(*itt).first <=> (itt->first)"<<endl;

    for(itt = v_p.begin(); itt != v_p.end(); ++itt){
        cout<<(itt->first)<<" "<<(itt->second)<<endl;
    }

    for(pair<int, int> &value : v_p){
        cout<<value.first<<" "<<value.second<<endl;
    }
    cout<<endl;

    cout<<"Using auto"<<endl;

    for(auto &value : v_p){
        cout<<value.first<<" "<<value.second<<endl;
    }
    cout<<endl;
    return 0;
}