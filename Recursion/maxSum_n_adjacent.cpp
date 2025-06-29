#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include<climits>
using namespace std;
int maxSum(int ind, vector <int> &nums){
    if(ind == 0){
        return nums[0];
    }
    if(ind < 0){
        return 0;
    }

    int pick = nums[ind] + maxSum(ind - 2, nums);
    int npick = 0 + maxSum(ind - 1, nums);

    return max(pick, npick);
}

int main(){
    vector<int> nums = {114,117,207,117,235,82,90,67,143,146,53,108,200,91,80,223,58,170,110,236,81,90,222,160,165,195,187,199,114,235,197,187,69,129,64,214,228,78,188,67,205,94,205,169,241,202,144,240};
    int n = nums.size();
    
    cout<<maxSum(n-1, nums)<<endl;

    return 0;
}