#include <iostream>
#include <vector>
using namespace std;
//Tabulation
//TC : O(N x target) + O(totalSum/2) + O(N)
//SC : O(N x target)

int main(){
    vector<int> arr = {1,2,3,5 };
    int n = arr.size();
    int totalSum = 0;

    for(int i = 0; i < n; i++){
        totalSum = totalSum + arr[i];
    }

    vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, 0));
    for(int i = 0; i < n; i++){
        dp[i][0] = true;
    }

    if(arr[0] <= totalSum){
        dp[0][arr[0]] = true;
    }

    for(int ind = 1; ind < n; ind++){
        for(int target = 1; target <= totalSum; target++){
            bool notTake = dp[ind - 1][target];
            bool take = false;
            if(target >= arr[ind]){
                take = dp[ind - 1][target - arr[ind]];
            }
            dp[ind][target] = take | notTake;;
        }
    }

    int mini = 1e9;
    for(int s1 = 0; s1 < totalSum/2; s1++){
        if(dp[n-1][s1] == true){
            mini = min(mini, abs(s1 - (totalSum - s1)));
        }
    }

    cout<<mini<<endl;

    return 0;
}