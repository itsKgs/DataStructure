#include <iostream>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int minPathSum(int row, int col, int m, vector<vector<int>>& grid){
    if(row == m){
        return grid[row][col];
    }

    int up = grid[row][col] + minPathSum(row + 1, col + 1, m, grid);
    int left = grid[row][col] + minPathSum(row + 1, col, m, grid);

    return min(up, left);
}

int main(){
    vector<vector<int>> grid = {{2},{3,4},{6,5,7},{4,1,8,3}};
    int m = grid.size();
    int n = grid[0].size();
    cout<<minPathSum(0, 0, m - 1, grid)<<endl;
    return 0;
}