#include <iostream>
#include <vector>
using namespace std;
//Memoization
//TC : O(N x target)
//SC : O(N x target) + O(N)
int countPartition(vector<int>& arr, int n, int targetSum){
    vector<vector<int>> dp(n, vector<int>(targetSum + 1, 0));

    if(arr[0] == 0){
        dp[0][0] = 2;
    }
    else{
        dp[0][0] = 1;
    }

    if(arr[0] != 0 && arr[0] <= targetSum){
        dp[0][arr[0]] = 1;
    }

    for(int ind = 1; ind < n; ind++){
        for(int target = 0; target <= targetSum; target++){
            int notTake = dp[ind - 1][target];
            int take = 0;
            if(target >= arr[ind]){
                take = dp[ind - 1][target - arr[ind]];
            }
            dp[ind][target] = take + notTake;
        }
    }
    return dp[n - 1][targetSum];
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