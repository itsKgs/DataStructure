#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// Tabulation

int main(){
    vector<vector<int>> grid = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));
    
    for(int col1 = 0; col1 < n; col1++){
        for(int col2 = 0; col2 < n; col2++){
            if(col1 == col2){
                dp[m-1][col1][col2] = grid[m-1][col1];
            }
            else{
                dp[m-1][col1][col2] = grid[m-1][col1] + grid[m-1][col2];
            }
        }
    }

    for(int row1 = m - 2; row1 >= 0; row1--){
        for(int col1 = 0; col1 < n; col1++){
            for(int col2 = 0; col2 < n; col2++){
                int maxi = -1e8;
                for(int R1col1 = -1; R1col1 <= 1; R1col1++){
                    for(int R2col2 = -1; R2col2 <= 1; R2col2++){
                        int value = 0;
                        if(col1 == col2){
                            value = grid[row1][col1];
                        }
                        else{
                            value = grid[row1][col1] + grid[row1][col2];
                        }
                        if(col1 + R1col1 >= 0 && col1 + R1col1 < n && col2 + R2col2 >= 0 && col2 + R2col2 < n){
                            value = value + dp[row1 + 1][col1 + R1col1][col2 + R2col2];
                        }
                        else{
                            value = -1e8;
                        }
                        maxi = max(maxi, value);
                    }
                    dp[row1][col1][col2] = maxi;
                }
            }
        }
    }
    cout<<dp[0][0][n-1]<<endl;

    return 0;
}