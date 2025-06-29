#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int frogJump_K(int ind, int k, vector<int> &heights){
    if(ind == 0){
        return 0;
    }
    int minJump = INT_MAX;
    for (int i = 1; i <= k; i++){
        if((ind - i) >= 0){
            int jump = frogJump_K(ind - i, k, heights) + abs(heights[ind] - heights[ind - i]);
            minJump = min(minJump, jump);
        }
    }
    return minJump;
}

int main(){
    int n, k = 4;
    vector<int> heights{40, 10, 20, 70, 80, 10, 20, 70, 80, 60};
    n = heights.size();

    cout<<frogJump_K(n-1, k, heights)<<endl;
    return 0;
}