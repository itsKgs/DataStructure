#include <iostream>
#include <vector>
using namespace std;
//TC : O(2^N)
//SC :+ O(N)
int targetSum(int ind, int target, vector<int>& arr){
    if(target == 0){
        return 1;
    }
    if(ind == 0){
        return (arr[0] == target);
        //if(arr[0] == target){
        //    return 1;
        //}
        //else{
        //    return 0;
        //}
    }

    int notTake = targetSum(ind - 1, target, arr);
    
    int take = 0;
    if(target >= arr[ind]){
        take = targetSum(ind - 1, target - arr[ind], arr);
    }
    return take + notTake;
}

int main(){
    vector<int> arr = {1,4,4,5};
    int n = arr.size();
    int target = 5;

    cout<<targetSum(n - 1, target, arr)<<endl;

    return 0;
}