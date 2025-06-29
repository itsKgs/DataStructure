#include <iostream>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
//Memoization
using namespace std;
int minPathSum(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){
    if(row == 0 && col == 0){
        return grid[0][0];
    }
    if(row < 0 || col < 0){
        return 1e9;
    }
    if(dp[row][col] != -1){
        return dp[row][col];
    }

    int up = grid[row][col] + minPathSum(row - 1, col, grid, dp);
    int left = grid[row][col] + minPathSum(row, col - 1, grid, dp);
    dp[row][col] = min(up, left);

    return dp[row][col];
}

int main(){
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout<<minPathSum(m - 1, n - 1, grid, dp)<<endl;
    return 0;
}