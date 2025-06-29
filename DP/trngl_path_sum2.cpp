#include <iostream>
#include <vector>
#include <bits/stdc++.h>
//Memorization
using namespace std;
int minPathSum(int row, int col, int m, vector<vector<int>>& grid, vector<vector<int>>& dp){
    if(row == m){
        return grid[row][col];
    }
    if(dp[row][col] != -1){
        return dp[row][col];
    }

    int up = grid[row][col] + minPathSum(row + 1, col + 1, m, grid, dp);
    int left = grid[row][col] + minPathSum(row + 1, col, m, grid, dp);
    dp[row][col] = min(up, left);

    return dp[row][col];
}

int main(){
    vector<vector<int>> grid = {{2},{3,4},{6,5,7},{4,1,8,3}};
    int m = grid.size();
    vector<vector<int>> dp(m, vector<int>(m, -1));
    cout<<minPathSum(0, 0, m - 1, grid, dp)<<endl;
    return 0;
}