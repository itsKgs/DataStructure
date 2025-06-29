#include <iostream>
#include <vector>
using namespace std;
//Tabulation
//TC : O(N x target)
//SC : O(N x target)

int main(){
    vector<int> arr = {1,4,4,5};
    int n = arr.size();
    int targetSum = 5;
    vector<vector<int>> dp(n, vector<int>(targetSum + 1, 0));
    for(int i = 0; i < n; i++){
        dp[i][0] = 1;
    }
    if(arr[0] <= targetSum){
        dp[0][arr[0]] = 1;
    }

    for(int ind = 1; ind < n; ind++){
        for(int target = 1; target <= targetSum; target++){
            int notTake = dp[ind - 1][target];
            int take = 0;
            if(target >= arr[ind]){
                take = dp[ind - 1][target - arr[ind]];
            }
            dp[ind][target] = take + notTake;;
        }
    }
    cout<<dp[n-1][targetSum]<<endl;

    return 0;
}