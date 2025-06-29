#include <iostream>
using namespace std;
//TC : log n(base 2)
int search(int low, int high, int target, int nums[]){
    if(low > high){
        return -1;
    }
    int mid = (low + high)/2;
    if(nums[mid] == target){
        return mid;
    }
    else if(nums[mid] < target){
        return search(mid + 1, high, target, nums);
    }
    else{
        return search(low, mid - 1, target, nums);
    }
}

int main(){
    int nums[] = {-1,0,3,5,9,12};
    int target = 9;
    int n = sizeof(nums)/sizeof(nums[0]);
    cout<<search(0, n - 1, target, nums)<<endl;
    return 0;
}