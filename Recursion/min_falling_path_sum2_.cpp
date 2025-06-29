#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int minPathSum(int row, int prevCol, int m, int n, vector<vector<int>>& grid){
    if(row < 0){
        return 0;
    }

    int temp = 1e9;
    for(int col = 0; col < n; col++){
        if(col != prevCol){
            temp = min(temp, grid[row][col] + minPathSum(row - 1, col, m, n, grid));
        }
    }
    return temp;
}

int main(){
    vector<vector<int>> grid = {{7}};
    int m = grid.size();
    int n = grid[0].size();

    int ans = 1e9;
    for(int col = 0; col < n; col++){
        ans = min(ans, grid[m-1][col] + minPathSum(m - 2, col, m, n, grid));
    }
    cout<<ans<<endl;

    return 0;
}