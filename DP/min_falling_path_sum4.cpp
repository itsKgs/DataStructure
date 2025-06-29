#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int minPathSum(vector<vector<int>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int>prev(n, 0);

    for(int col = 0; col < n; col++){
        prev[col] = matrix[0][col];
    }

    for(int row = 1; row < m; row++){
        vector<int>curr(n, 0);
        for(int col = 0; col < n; col++){
            int down = matrix[row][col] + prev[col];

            int left = matrix[row][col];
            if(col < n - 1){
                left = matrix[row][col] + prev[col + 1];
            }
            else{
                left = 1e9;
            }

            int right = matrix[row][col];
            if(col >= 0){
                right = matrix[row][col] + prev[col - 1];
            }
            else{
                right = 1e9;
            }
            curr[col] = min(down, min(left, right));
        }
        prev = curr;
    }

    int ans = 1e9; 
    for(int col = 0; col < n; col++){
        ans = min(ans, prev[col]);
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix = {{-19,57},{-40,-5}};
    cout<<minPathSum(matrix)<<endl;
    return 0;
}