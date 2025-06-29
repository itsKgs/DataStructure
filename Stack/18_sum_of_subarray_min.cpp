#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {3,1,2,4};
    int n = nums.size();

    int sum = 0; 
    for(int i = 0; i < n; i++){
        vector<int> temp;
        int j = i;
        while(j < n){
            temp.push_back(nums[j]);
            auto minmax = minmax_element(temp.begin(), temp.end());
            sum = sum + *minmax.first;
            j++;
        }
    }

    cout<<sum<<endl;
    return 0;
}