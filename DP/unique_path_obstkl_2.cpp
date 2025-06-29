#include <iostream>
#include <vector>
#include <bits/stdc++.h>
//Memoization
using namespace std;
int paths(int row, int col, vector<vector<int>>& dp, vector<vector<int>>& nums){
    if(row >= 0 && col >= 0 && nums[row][col] == 1){
        return 0;
    }
    if(row == 0 && col == 0){
        return 1;
    }
    if(row < 0 || col < 0){
        return 0;
    }
    if(dp[row][col] != -1){
        return dp[row][col];
    }
    int up = paths(row-1, col, dp, nums);
    int down = paths(row, col-1, dp, nums);

    dp[row][col] = up + down;
    return dp[row][col];
}

int main(){
    int m = 3, n = 3;
    vector<vector<int>>nums = {{0,0,0},{0,1,0},{0,0,0}};
    vector<vector<int>> dp(m, vector<int>(n, -1));

    cout<<paths(m - 1, n - 1, dp, nums) <<endl;

    return 0;
}