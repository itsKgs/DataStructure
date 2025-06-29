#include <iostream>
#include <vector>
#include <bits/stdc++.h>
//Space Optimization
using namespace std;
int main(){
    int m = 3, n = 3;
    vector<vector<int>>nums = {{0,0,0},{0,1,0},{0,0,0}};
    vector<int> prev(n, 0);

    for(int i = 0; i < m; i++){
        vector<int> curr(n, 0);
        for(int j = 0; j < n; j++){
            if(nums[i][j] == 1){
                curr[j] = 0; 
            }
            else if(i == 0 && j == 0){
                curr[0] = 1;
            }
            else{
                int up = 0;
                int left = 0;
                if(i > 0){
                    up = prev[j]; 
                }
                if(j > 0){
                    left = curr[j-1];
                }
                curr[j] = up + left;
            }
        }
        prev = curr;
    }
    cout<<prev[n-1]<<endl;

    return 0;
}