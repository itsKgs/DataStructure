#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
    int n=7;
    vector <int> nums={1,2,3,4,5,6,7};
    int k=3;

    //int temp[k];
    //for (int i = 0; i < k; i++){
    //    temp[i]=arr[i];
    //}

    //for (int i = k; i < 7; i++){
    //    arr[i-k]=arr[i];
    //}
    
    //for (int i = n-k; i < n; i++){
    //    arr[i]=temp[i-(n-k)];
    //}


    reverse(nums.begin(), nums.begin()+k);
    reverse(nums.begin()+k, nums.end());
    reverse(nums.begin(), nums.end());

    for (int j = 0; j < nums.size(); j++){
        cout<<nums[j]<<" ";
    }
    
    return 0;
}