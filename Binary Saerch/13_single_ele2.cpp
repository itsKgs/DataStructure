#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    int n = nums.size();
    if(n == 1){
        cout<<nums[0]<<endl;
    }
    if(nums[0] != nums[1]){
        cout<<nums[0]<<endl;
    }
    if(nums[n-1] != nums[n-2]){
        cout<<nums[n-1]<<endl;
    }
        
    int low = 1;
    int high = n - 2;

    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] != nums[mid -1] && nums[mid] != nums[mid + 1]){
            cout<<nums[mid]<<endl;
        }
        //Left Half
        if((mid%2 != 0 && nums[mid] == nums[mid - 1]) ||mid%2 == 0 &&  nums[mid] == nums[mid + 1]){
            low = mid + 1; //Eliminate left half
        }
        else{
            high = mid - 1; // Eliminate Right Half
        }
    }

    return 0;
}