#include<iostream>
#include<bits/stdc++.h>
#include<vector>
// Space Optimization
using namespace std;
int main(){
    vector<int> heights{7, 4, 4, 2, 6, 6, 3, 4 };
    int n = heights.size();

    int prev2 = 0;
    int prev = abs(heights[0] - heights[1]);
    if(n == 1){
        cout<<prev2<<endl;
    }
    if(n == 2){
        cout<<prev<<endl;
    }

    for(int i = 2; i < n; i++){
        int jump1 = prev + abs(heights[i] - heights[i-1]);
        int jump2 = prev2 + abs(heights[i] - heights[i-2]);
        int curr = min(jump1, jump2);
        prev2 = prev;
        prev = curr;
    }
    cout<<prev<<endl;
    return 0;
}