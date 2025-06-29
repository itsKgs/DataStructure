#include <iostream>
#include <vector>
using namespace std;
//Tabulation
//TC : O(N x target) + O(totalSum/2) + O(N)
//SC : O(target)

int main(){
    vector<int> arr = {3,9,7,3};
    int n = arr.size();
    int totalSum = 0;

    for(int i = 0; i < n; i++){
        totalSum = totalSum + arr[i];
    }

    vector<bool> prev(totalSum + 1, 0), curr(totalSum + 1, 0);
    prev[0] = curr[0] = true;
    if(arr[0] <= totalSum){
        prev[arr[0]] = true;
    }

    for(int ind = 1; ind < n; ind++){
        for(int target = 1; target <= totalSum; target++){
            bool notTake = prev[target];
            bool take = false;
            if(target >= arr[ind]){
                take = prev[target - arr[ind]];
            }
            curr[target] = take | notTake;;
        }
        prev = curr;
    }

    int mini = 1e9;
    for(int s1 = 0; s1 < totalSum/2; s1++){
        if(prev[s1] == true){
            mini = min(mini, abs(s1 - (totalSum - s1)));
        }
    }

    cout<<mini<<endl;

    return 0;
}