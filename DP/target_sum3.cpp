#include <iostream>
#include <vector>
using namespace std;
//Tabulation
//TC : O(N x target)
//SC : O(N x target)

int main(){
    vector<int> arr = {1,4,3,2};
    int n = arr.size();
    int targetSum = 5;
    vector<vector<bool>> dp(n, vector<bool>(targetSum + 1, 0));
    for(int i = 0; i < n; i++){
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;

    for(int ind = 1; ind < n; ind++){
        for(int target = 1; target <= targetSum; target++){
            bool notTake = dp[ind - 1][target];
            bool take = false;
            if(target >= arr[ind]){
                take = dp[ind - 1][target - arr[ind]];
            }
            dp[ind][target] = take | notTake;;
        }
    }
    cout<<dp[n-1][targetSum]<<endl;

    return 0;
}