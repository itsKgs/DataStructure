#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <utility>
using namespace std;

int main(){
    vector<int> nums = {995,997,997,997,999,997}; 
    int key = 997;

    unordered_map<int, int> mp;
    for(int i = 1; i < nums.size(); i++){
        if(nums[i-1] == key){
            mp[nums[i]]++;
            
        }
    }
    //for(auto &it : mp){
    //    cout<<it.first<<" "<<it.second<<endl;
    //}
    pair<int, int> max = make_pair(0,0);
    for(auto &it : mp){
        if(it.second > max.second){
            max = it;
        }
    }
    cout<<max.first<<endl;
    return 0;
}