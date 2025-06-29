#include <iostream>
#include <vector>
using namespace std;
//TC : O(log n)
//SC : O(1)
int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    int n = nums.size();
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == target){
            cout<<"true"<<endl;
        }
        if(nums[low] == nums[mid] && nums[mid] == nums[high]){
            low = low + 1;
            high = high - 1;
            continue;
        }
        if(nums[low] <= nums[mid]){//left sorted
            if(nums[low] <= target && target <= nums[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{//right sorted
            if(nums[mid] <= target && target <= nums[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1; 
            }
        }
    }
    cout<<"false"<<endl;

    return 0;
}