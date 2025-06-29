#include <iostream>
#include <vector>
#include <bits/stdc++.h>
//Tabulation
using namespace std;
int main(){
    int m = 3, n = 3;
    vector<vector<int>>nums = {{0,0,0},{0,1,0},{0,0,0}};
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(nums[i][j] == 1){
                dp[i][j] = 0;
            }
            else if(i == 0 && j == 0){
                dp[0][0] = 1;
            }
            else{
                int up = 0;
                int left = 0;
                if(i > 0){
                    up = dp[i-1][j]; 
                }
                if(j > 0){
                    left = dp[i][j-1];
                }
                dp[i][j] = up + left;
            }
        }
    }
    cout<<dp[m-1][n-1]<<endl;

    return 0;
}