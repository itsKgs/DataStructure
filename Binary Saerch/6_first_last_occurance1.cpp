#include <iostream>
#include <vector>
using namespace std;
// TC : O(2 * log n)
// SC : O(1)
int lowerBound(vector<int>& nums, int target){
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = n;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] >= target){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int upperBound(vector<int>& nums, int target){
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = n;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] > target){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    int n = nums.size();
    int lb = lowerBound(nums, target);
    if(lb == n || nums[lb] != target){
        cout<<"{-1,-1}"<<endl;
    }
    else{
        cout<<"{"<<lb<<","<<upperBound(nums, target) - 1<<"}"<<endl;
    }

    return 0;
}