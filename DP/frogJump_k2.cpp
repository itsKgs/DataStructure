#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
// Memorization
int frogJump_K(int ind, int k, vector<int> &heights, vector<int> &dp){
    if(ind == 0){
        return 0;
    }
    if(dp[ind] != -1){
        return dp[ind];
    }
    
    int minJump = INT_MAX;
    for (int i = 1; i <= k; i++){
        if((ind - i) >= 0){
            int jump = frogJump_K(ind - i, k, heights, dp) + abs(heights[ind] - heights[ind - i]);
            minJump = min(minJump, jump);
        }
    }

    dp[ind] = minJump;
    return dp[ind];
}

int main(){
    int n, k = 4;
    vector<int> heights{40, 10, 20, 70, 80, 10, 20, 70, 80, 60};
    n = heights.size();

    vector<int> dp(n, -1);

    cout<<frogJump_K(n-1, k, heights, dp)<<endl;
    return 0;
}