#include <iostream>
#include <vector>
using namespace std;
//Memoization
//TC : O(2^n x target)
//SC : O(N x target) + O(N)
int targetSum(int ind, int target, vector<int>& arr, vector<vector<int>>& dp){
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

int countPartition(vector<int>& arr, int n, int target){
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return targetSum(n - 1, target, arr, dp);
}

int main(){
    vector<int> arr = {1,1,1,1};
    int n = arr.size();
    int d = 0;

    int totalSum = 0;
    for(int i = 0; i < n; i++){
        totalSum = totalSum + arr[i];
    }

    if(totalSum - d < 0 || (totalSum - d)%2 != 0){
        cout<<"0"<<endl;
        return 0;
    }

    cout<<countPartition(arr, n, (totalSum - d)/2)<<endl;


    return 0;
}