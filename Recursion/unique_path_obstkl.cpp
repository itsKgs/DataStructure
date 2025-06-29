#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int uniquePaths(int row, int col, vector<vector<int>>& nums) {
    if(row >= 0 && col >= 0 && nums[row][col] == 1){
        return 0;
    }
    if(row == 0 && col == 0){
        return 1;
    }
    if(row < 0 || col < 0){
        return 0;
    }
    int l = uniquePaths(row-1, col, nums);
    int r = uniquePaths(row, col-1, nums);
    return l + r;
}

int main(){
    int m = 3, n = 3;
    vector<vector<int>>nums = {{0,0,0},{0,1,0},{0,0,0}};

    cout<<uniquePaths(m - 1, n - 1, nums)<<endl;

    return 0;
}