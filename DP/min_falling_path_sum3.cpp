#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int minPathSum(vector<vector<int>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>>dp(m, vector<int>(n, 0));

    for(int col = 0; col < n; col++){
        dp[0][col] = matrix[0][col];
    }

    for(int row = 1; row < m; row++){
        for(int col = 0; col < n; col++){
            int down = matrix[row][col] + dp[row - 1][col];

            int left = matrix[row][col];
            if(col < n - 1){
                left = matrix[row][col] + dp[row - 1][col + 1];
            }
            else{
                left = 1e9;
            }

            int right = matrix[row][col];
            if(col >= 0){
                right = matrix[row][col] + dp[row - 1][col - 1];
            }
            else{
                right = 1e9;
            }

            dp[row][col] = min(down, min(left, right));

        }
    }

    int ans = 1e9; 
    for(int col = 0; col < n; col++){
        ans = min(ans, dp[m-1][col]);
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix = {{-19,57},{-40,-5}};
    cout<<minPathSum(matrix)<<endl;
    return 0;
}