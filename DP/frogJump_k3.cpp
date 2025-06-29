#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
// Tabulation

int main(){
    int n, k = 4;
    vector<int> heights{40, 10, 20, 70, 80, 10, 20, 70, 80, 60};
    n = heights.size();

    vector<int> dp(n, -1);

    dp[0] = 0;
    for(int i = 1; i < n; i++){
        int minJump = INT_MAX;
        for(int j = 1; j <= k; j++){
            if(i - j >= 0){
                int jump = dp[i-j] + abs(heights[i] - heights[i-j]);
                minJump = min(minJump, jump);
            }
        }
        dp[i] = minJump;
    }

    cout<<dp[n-1]<<endl;
    return 0;
}