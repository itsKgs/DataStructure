#include <iostream>
#include <vector>
using namespace std;
//Tabulation
//TC : O(N x target)
//SC : O(N x target)

int main(){
    vector<int> arr = {0,0,1};
    int n = arr.size();
    int targetSum = 1;
    vector<int> prev(targetSum + 1, 0), curr(targetSum + 1, 0);
    prev[0] = curr[0] = 1;

    if(arr[0] <= targetSum){
        prev[arr[0]] = 1;
    }

    for(int ind = 1; ind < n; ind++){
        for(int target = 1; target <= targetSum; target++){
            int notTake = prev[target];
            int take = 0;
            if(target >= arr[ind]){
                take = prev[target - arr[ind]];
            }
            curr[target] = take + notTake;;
        }
        prev = curr;
    }
    cout<<prev[targetSum]<<endl;

    return 0;
}