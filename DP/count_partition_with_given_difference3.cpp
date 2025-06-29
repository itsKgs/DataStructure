#include <iostream>
#include <vector>
using namespace std;
//Memoization
//TC : O(N x target)
//SC : O(N x target)
int countPartition(vector<int>& arr, int n, int targetSum){
    vector<int> prev(targetSum + 1, 0), curr(targetSum + 1, 0);

    if(arr[0] == 0){
        prev[0] = 2;
    }
    else{
        prev[0] = 1;
    }

    if(arr[0] != 0 && arr[0] <= targetSum){
        prev[arr[0]] = 1;
    }

    for(int ind = 1; ind < n; ind++){
        for(int target = 0; target <= targetSum; target++){
            int notTake = prev[target];
            int take = 0;
            if(target >= arr[ind]){
                take = prev[target - arr[ind]];
            }
            curr[target] = take + notTake;
        }
        prev = curr;
    }
    return prev[targetSum];
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