#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int minPathSum(int row, int col, int m, int n, vector<vector<int>>& grid){
    if(col >= n || col < 0){
        return 1e9;
    }

    if(row == m - 1){
        return grid[row][col];
    }

    int down = grid[row][col] + minPathSum(row + 1, col, m, n, grid);
    int left = grid[row][col] + minPathSum(row + 1, col + 1, m, n, grid);
    int right = grid[row][col] + minPathSum(row + 1, col - 1, m, n, grid);

    return min(down, min(left, right));
}

int main(){
    vector<vector<int>> grid = {{-19,57},{-40,-5}};
    int m = grid.size();
    int n = grid[0].size();

    int ans = 1e9;
    for(int col = 0; col < n; col++){
        ans = min(ans, minPathSum(0, col, m, n, grid));
    }
    cout<<ans<<endl;

    return 0;
}