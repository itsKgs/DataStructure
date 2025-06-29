#include <iostream>
#include <vector>
#include<climits>
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> grid = {{-73,61,43,-48,-36},{3,30,27,57,10},{96,-76,84,59,-15},{5,-49,76,31,-7},{97,91,61,-46,67}};
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for(int col = 0; col < n; col++){
        dp[0][col] = grid[0][col];
    }

    for(int row = 1; row < m; row++){
        for(int prevCol = 0; prevCol < n; prevCol++){
            for(int col = 0; col < n; col++){
                if(col != prevCol){
                    int temp = grid[row][col] + dp[row - 1][col];
                    dp[row][prevCol] = min(dp[row][prevCol], temp);
                }
            }
        }
    }

    int ans = 1e9;
    for(int col = 0; col < n; col++){
        ans = min(ans, dp[m-1][col]);
    }

    cout<<ans<<endl;
    return 0;
}