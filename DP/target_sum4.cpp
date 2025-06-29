#include <iostream>
#include <vector>
using namespace std;
//Tabulation
//TC : O(N x target)
//SC : O(target)

int main(){
    vector<int> arr = {1,4,3,2};
    int n = arr.size();
    int targetSum = 5;
    vector<bool> prev(targetSum + 1, 0), curr(targetSum + 1, 0);
    prev[0] = curr[0] = true;
    prev[arr[0]] = true;

    for(int ind = 1; ind < n; ind++){
        for(int target = 1; target <= targetSum; target++){
            bool notTake = prev[target];
            bool take = false;
            if(target >= arr[ind]){
                take = prev[target - arr[ind]];
            }
            curr[target] = take | notTake;;
        }
        prev = curr;
    }
    cout<<prev[targetSum]<<endl;

    return 0;
}