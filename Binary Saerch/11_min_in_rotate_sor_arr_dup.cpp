#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int n = nums.size();
    int ans = INT_MAX;
    int low = 0;
    int high = n - 1;

    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[low] == nums[mid] && nums[mid] == nums[high]){
            low = low + 1;
            high = high - 1;
            continue;
        }
        if(nums[low] <= nums[mid]){
            ans = min(ans, nums[low]);
            low = mid + 1;
        }
        else{
            ans = min(ans, nums[mid]);
            high = mid - 1;
        }
    }
    cout<<ans<<endl;

    return 0;
}