#include<iostream>
#include<bits/stdc++.h>
#include<vector>
// Tabulation
using namespace std;
int main(){
    vector<int> heights{7,4,4,2,6,6,3,4};
    int n = heights.size();

    vector<int> dp(n, -1);

    dp[0] = 0;
    dp[1] = abs(heights[0] - heights[1]);
    for(int i = 2; i < n; i++){
        int jump1 = dp[i-1] + abs(heights[i] - heights[i-1]);
        int jump2 = dp[i-2] + abs(heights[i] - heights[i-2]);
        dp[i] = min(jump1, jump2);
    }
    cout<<dp[n-1]<<endl;
    return 0;
}