#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include<climits>
// Tabulation
using namespace std;

int main(){
    vector<int> nums = {2,7,9,3,1};
    int n = nums.size();
    vector<int> dp(n, -1);
    dp[0] = nums[0];
    
    for(int i = 1; i < n; i++){
        int pick =  nums[i];
        if(i > 1){
            pick =  nums[i] + dp[i - 2];
        }
        int npick = dp[i - 1];
        dp[i] = max(pick, npick); 
    }
    cout<<dp[n-1]<<endl;
    return 0;
}