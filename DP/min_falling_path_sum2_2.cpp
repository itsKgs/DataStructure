#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int minPathSum(int row, int prevCol, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
    if(row < 0){
        return 0;
    }
    if(dp[row][prevCol] != -1){
        return dp[row][prevCol];
    }

    int temp = 1e9;
    for(int col = 0; col < n; col++){
        if(col != prevCol){
            temp = min(temp, grid[row][col] + minPathSum(row - 1, col, m, n, grid, dp));
        }
    }

    dp[row][prevCol] = temp;
    return dp[row][prevCol];
}

int main(){
    vector<vector<int>> grid = {{-73,61,43,-48,-36},{3,30,27,57,10},{96,-76,84,59,-15},{5,-49,76,31,-7},{97,91,61,-46,67}};
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    int ans = 1e9;
    for(int col = 0; col < n; col++){
        ans = min(ans, grid[m-1][col] + minPathSum(m - 2, col, m, n, grid, dp));
    }
    cout<<ans<<endl;

    return 0;
}