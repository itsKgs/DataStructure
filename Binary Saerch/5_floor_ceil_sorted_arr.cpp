#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//TC: log n + log n
int ceil(int low, int high, int target, int nums[]){
    int ans = -1;
    while(low <= high){
        int mid = (low + high)/2;

        if(nums[mid] >= target){
            ans = nums[mid];
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int floor(int low, int high, int target, int nums[]){
    int ans = -1;
    while(low <= high){
        int mid = (low + high)/2;

        if(nums[mid] <= target){
            ans = nums[mid];
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    int nums[] = {10, 20, 30, 40, 50};
    int target = 25;
    int n = sizeof(nums)/sizeof(nums[0]);
    cout<<ceil(0, n - 1, target, nums)<<endl;
    cout<<floor(0, n - 1, target, nums)<<endl;

    return 0;
}