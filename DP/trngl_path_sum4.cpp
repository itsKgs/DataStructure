#include <iostream>
#include <vector>
#include <bits/stdc++.h>
//Space Optimization
using namespace std;
int main(){
    vector<vector<int>> grid = {{2},{3,4},{6,5,7},{4,1,8,3}};
    int m = grid.size();
    vector<int> prev(m, 0);

    for(int i = m - 1; i >= 0; i--){
        vector<int> curr(m, 0);
        for(int j =  i; j >= 0; j--){
            if(i == m - 1){
                curr[j] = grid[i][j];
            }
            else{
                int up = grid[i][j] + prev[j + 1];
                int left = grid[i][j] + prev[j];
                curr[j] = min(up, left);
            }
        }
        prev = curr;
    }
    cout<<prev[0]<<endl;
    return 0;
}