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
    for(int i = 1; i <= mx; i++){
        if(sumOfD(nums, i) <= threshold){
            cout<<sumOfD(nums, i)<<endl;
            cout<<i<<endl;
            break;
        }
    }

    return 0;
}