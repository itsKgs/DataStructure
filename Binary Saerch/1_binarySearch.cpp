#include <iostream>
using namespace std;
//TC : log n(base 2)
int main(){
    int nums[] = {-1,0,3,5,9,12};
    int target = 9;
    int n = sizeof(nums)/sizeof(nums[0]);
    int low = 0;
    int high = n - 1;
    while(low <= high){
        int mid = (low + high)/2;
        if(nums[mid] == target){
            cout<<mid<<endl;
            return 0;
        }
        else if(nums[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    cout<<"-1"<<endl;
    return 0;
}