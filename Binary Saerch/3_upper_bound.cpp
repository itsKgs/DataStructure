#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//TC: log n
int lowerBound(int low, int high, int target, int nums[]){
    int ans = high + 1;
    while(low <= high){
        int mid = (low + high)/2;

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

//int main(){
//    int nums[] = {1,2,3,3,5,8,8,10,10,11};
//    int target = 9;
//    int n = sizeof(nums)/sizeof(nums[0]);
//    cout<<lowerBound(0, n - 1, target, nums)<<endl;
//    return 0;
//}

int main() {
    vector<int> nums = {2,3,6,7,8,8,11,11,11,12}; 
    int target = 10; // Value to search for

    int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    
    cout << "Upper bound index: " << ub << endl;
    return 0;
}