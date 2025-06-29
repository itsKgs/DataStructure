#include <iostream>
#include <vector>
using namespace std;
//Memoization
//TC : O(N x target)
//SC : O(N x target) + O(N)
int targetSum(int ind, int target, vector<int>& arr, vector<vector<int>>& dp){
    //if(target == 0){
    //    return 1;
    //}
    //if(ind == 0){
    //    return (arr[0] == target);
    //}
    if(ind == 0){
        if(target == 0 && arr[0] == target){
            return 2;
        }
        if(target == 0 || arr[0] == target){
            return 1;
        }
        return 0;
    }

    if(dp[ind][target] != -1){
        return dp[ind][target];
    }

    int notTake = targetSum(ind - 1, target, arr, dp);
    
    int take = 0;
    if(target >= arr[ind]){
        take = targetSum(ind - 1, target - arr[ind], arr, dp);
    }
    dp[ind][target] = take + notTake;
    return dp[ind][target];
}

int main(){
    vector<int> arr = {0,0,1};
    int n = arr.size();
    int target = 1;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    cout<<targetSum(n - 1, target, arr, dp)<<endl;

    return 0;
}