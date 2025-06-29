#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int maxCherryPickup(int row1, int col1, int col2, int row, int col, vector<vector<int>> grid){
    if(col1 < 0 || col1 >= col || col2 < 0 || col2 >= col){
        return -1e8;
    }
    if(row1 == row - 1){
        if(col1 == col2){
            return grid[row1][col1];
        }
        else{
            return grid[row1][col1] + grid[row1][col2];
        }
    }

    int maxi = -1e8;
    for(int R1col1 = -1; R1col1 <= 1; R1col1++){
        for(int R2col2 = -1; R2col2 <= 1; R2col2++){
            int value = 0;
            if(col1 == col2){
                value = grid[row1][col1] + maxCherryPickup(row1 + 1, col1 + R1col1, col2 + R2col2, row, col, grid);
            }
            else{
                value = grid[row1][col1] + grid[row1][col2]+ maxCherryPickup(row1 + 1, col1 + R1col1, col2 + R2col2, row, col, grid);
            }
            maxi = max(maxi, value);
        }
    }
    return maxi;
}

int main(){
    vector<vector<int>> grid = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    int m = grid.size();
    int n = grid[0].size();

    cout<<maxCherryPickup(0, 0, n-1, m, n, grid);

    return 0;
}