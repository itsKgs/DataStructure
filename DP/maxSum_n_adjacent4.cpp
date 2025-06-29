#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include<climits>
// Space Optimization
using namespace std;

int main(){
    vector<int> nums = {2,1,1,2};
    int n = nums.size();
    //int prev2 = nums[0];
    //int prev = nums[1];
    int prev = 0, prev2 = 0;
    for(int i = 0; i < n; i++){
        int pick =  nums[i] + prev2;
        int npick = prev;
        int curr = max(pick, npick); 
        prev2 = prev;
        prev = curr;
    }
    cout<<prev<<endl;
    return 0;
}