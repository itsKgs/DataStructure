#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    int n = nums.size();
    if(n == 1){
        return nums[0];
    }
    for(int i = 0; i < n; i++){
        if(i == 0){
            if(nums[i] != nums[i+1]){
                cout<<nums[i]<<endl;
            }
        }
        else if(i == n-1){
            if(nums[i] != nums[i-1]){
                cout<<nums[i]<<endl;
            }
        }
        else{
            if(nums[i] != nums[i-1] && nums[i] != nums[i+1]){
                cout<<nums[i]<<endl;
            }
        }
    }

    return 0;
}