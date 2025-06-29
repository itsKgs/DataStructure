#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int minPathSum(int row, int col, vector<vector<int>>& grid){
    if(row == 0 && col == 0){
        return grid[0][0];
    }
    if(row < 0 || col < 0){
        return INT_MAX/2;
    }

    int up = grid[row][col] + minPathSum(row - 1, col, grid);
    int left = grid[row][col] + minPathSum(row, col - 1, grid);

    return min(up, left);
}

int main(){
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    int m = grid.size();
    int n = grid[0].size();
    cout<<minPathSum(m - 1, n - 1, grid)<<endl;
    return 0;
}