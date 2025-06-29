#include <iostream>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
//Tabulation
using namespace std;

int main(){
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0){
                dp[i][j] = grid[i][j];
            }
            else{
                int up = 0; 
                int left = 0;
                if(i > 0){
                    up = grid[i][j] + dp[i - 1][j];
                }
                else{
                    up = 1e9;
                }
                if(j > 0){
                    left = grid[i][j] + dp[i][j - 1];
                }
                else{
                    left = 1e9;
                }
                dp[i][j] = min(up, left);
            }
        }
    }
    cout<<dp[m-1][n-1]<<endl;
    return 0;
}