#include <iostream>
#include <vector>
#include <bits/stdc++.h>
//Tabulation
using namespace std;

int main(){
    vector<vector<int>> grid = {{2},{3,4},{6,5,7},{4,1,8,3}};
    int m = grid.size();
    vector<vector<int>> dp(m, vector<int>(m, 0));

    for(int i = m - 1; i >= 0; i--){
        for(int j =  i; j >= 0; j--){
            if(i == m - 1){
                dp[i][j] = grid[i][j];
            }
            else{
                int up = grid[i][j] + dp[i + 1][j + 1];
                int left = grid[i][j] + dp[i + 1][j];
                //int up = 0;
                //int left = 0;
                //if(i < m-1 && j < grid[i].size() - 1){
                //    up = grid[i][j] + dp[i + 1][j + 1];
                //}
                //else{
                //    up = 1e9;
                //}
                //if(j < m - 1){
                //    left = grid[i][j] + dp[i + 1][j];
                //}
                //else{
                //    left = 1e9;
                //}
                dp[i][j] = min(up, left);
            }
        }
    }
    cout<<dp[0][0]<<endl;
    return 0;
}