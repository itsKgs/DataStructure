#include <iostream>
#include <vector>
using namespace std;
// TC : O(2 * log n)
// SC : O(1)

int first(vector<int>& nums, int target){
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == target){
            ans = mid;
            high = mid - 1;
        }
        else if(nums[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

int last(vector<int>& nums, int target){
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == target){
            ans = mid;
            low = mid + 1;
        }
        else if(nums[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {5,7,7,8,8,10};
    int target = 6;
    int n = nums.size();
    if(first(nums, target) == -1){
        cout<<"0"<<endl;
    }
    else{
        cout<<last(nums, target) - first(nums, target) + 1<<endl;
    }

    return 0;
}