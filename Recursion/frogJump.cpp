#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int frogJump(int ind, vector<int> &heights){
    if(ind == 0){
        return 0;
    }
    if(ind == 1){
        return abs(heights[0] - heights[1]);
    }

    int l = frogJump(ind - 1, heights) + abs(heights[ind] - heights[ind - 1]);
    int r = frogJump(ind - 2, heights) + abs(heights[ind] - heights[ind - 2]);
    return min(l, r);

}

int main(){
    int n;
    vector<int> heights{7, 4, 4, 2, 6, 6, 3, 4};
    n = heights.size();

    cout<<frogJump(n-1, heights)<<endl;
}