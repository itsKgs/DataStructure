#include <iostream>
#include <vector>
using namespace std;
bool targetSum(int ind, int target, vector<int>& arr){
    if(target == 0){
        return true;
    }
    if(ind == 0){
        //return (arr[0] == target);
        if(arr[0] == target){
            return true;
        }
        else{
            return false;
        }
    }

    bool notTake = targetSum(ind - 1, target, arr);
    
    bool take = false;
    if(target >= arr[ind]){
        take = targetSum(ind - 1, target - arr[ind], arr);
    }
    return take | notTake;
}

int main(){
    vector<int> arr = {1,4,3,2};
    int n = arr.size();
    int target = 5;
    cout<<targetSum(n - 1, target, arr)<<endl;

    return 0;
}