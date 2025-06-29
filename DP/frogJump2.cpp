#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
// Memorization
int frogJump(int ind, vector<int> &heights, vector<int> &dp){
    if(ind == 0){
        return 0;
    }
    if(ind == 1){
        return abs(heights[0] - heights[1]);
    }

    if(dp[ind] != -1){
        return dp[ind];
    }

    int l = frogJump(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
    int r = frogJump(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);
    return dp[ind] = min(l, r);

}
int main(){
    vector<int> heights{10, 20, 30 ,10};
    int n = heights.size();

    vector<int> dp(n, -1);

    cout<<frogJump(n-1, heights, dp)<<endl;
}