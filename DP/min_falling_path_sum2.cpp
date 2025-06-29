#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
    int minPathSum(int row, int col, int m, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(col < 0 || col > n - 1){
            return 1e9;
        }
        if(row == m - 1){
            return matrix[row][col];
        }
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        int down = matrix[row][col] + minPathSum(row + 1, col, m, n, matrix, dp);
        int left = matrix[row][col] + minPathSum(row + 1, col - 1, m, n, matrix, dp);
        int right = matrix[row][col] + minPathSum(row + 1, col + 1, m, n, matrix, dp);
        dp[row][col] = min(min(down, left), right);
        
        return dp[row][col];
    }

int main(){
    vector<vector<int>> matrix = {{-19,57},{-40,-5}};
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>>dp(m, vector<int>(n, -1));

    int ans = 1e9;
    for(int col = 0; col < n; col++){
        ans = min(ans, minPathSum(0, col, m, n, matrix, dp));
    }
    cout<<ans<<endl;

    return 0;
}