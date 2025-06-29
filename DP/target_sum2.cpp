#include <iostream>
#include <vector>
using namespace std;
//Memoization
//TC : O(N x target)
//SC : O(N x target) + O(N)
bool targetSum(int ind, int target, vector<int>& arr, vector<vector<int>>& dp){
    if(target == 0){
        return true;
    }
    if(ind == 0){
        return (arr[0] == target);
        //if(arr[0] == target){
        //    return true;
        //}
        //else{
        //    return false;
        //}
    }

    if(dp[ind][target] != -1){
        return dp[ind][target];
    }

    bool notTake = targetSum(ind - 1, target, arr, dp);
    
    bool take = false;
    if(target >= arr[ind]){
        take = targetSum(ind - 1, target - arr[ind], arr, dp);
    }
    dp[ind][target] = take | notTake;
    return dp[ind][target];
}

int main(){
    vector<int> arr = {1,4,3,2};
    int n = arr.size();
    int target = 5;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    cout<<targetSum(n - 1, target, arr, dp)<<endl;

    return 0;
}