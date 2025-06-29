#include <iostream>
#include <vector>
#include <bits\stdc++.h>
using namespace std;

int sumOfD(vector<int> &nums, int d){
    int n = nums.size();
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum = sum + ceil((double)nums[i]/d);
    }
    return sum;
}


int main(){
    vector<int> nums = {1,2,5,9};
    int threshold = 6;
    int n = nums.size();
    int mx = *max_element(nums.begin(), nums.end());
    int low = 1;
    int high = mx;

    while(low <= high){
        int mid = low + (high - low)/2;
        if(sumOfD(nums, mid) <= threshold){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    cout<<low<<endl;

    return 0;
}