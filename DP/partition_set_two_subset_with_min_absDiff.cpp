#include <iostream>
#include <vector>
using namespace std;
//Memoization
//TC : O(2^n x target)
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
    vector<int> arr = {1,2,3,5};
    int n = arr.size();
    int totalSum = 0;
    for(int i = 0; i < n; i++){
        totalSum = totalSum + arr[i];
    }
    vector<vector<int>> dp(n, vector<int>(totalSum + 1, -1));

    int mini = 1e9;
    for(int s1 = 0; s1 < totalSum/2; s1++){
        if(targetSum(n - 1, s1, arr, dp)){
            mini = min(mini, abs(s1 - (totalSum - s1)));
        }
    }

    cout<<mini<<endl;


    return 0;
}