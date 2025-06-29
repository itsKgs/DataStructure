#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include<climits>
// Memorization
using namespace std;
int maxSum(int ind, vector <int> &nums, vector <int> &dp){
    if(ind == 0){
        return nums[0];
    }
    if(ind < 0){
        return 0;
    }
    if(dp[ind] != -1){
        return dp[ind];
    }

    int pick = nums[ind] + maxSum(ind - 2, nums, dp);
    int npick = 0 + maxSum(ind - 1, nums, dp);
    dp[ind] = max(pick, npick);

    return dp[ind];
}

int main(){
    vector<int> nums = {2,1,1,2};
    int n = nums.size();

    vector<int> dp(n, -1);
    
    cout<<maxSum(n-1, nums, dp)<<endl;

    return 0;
}