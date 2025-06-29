#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int SubSeq(int ind, int n, int sum, int k, int arr[]){
    if(sum > k){
        return 0;
    }
    if (ind == n){
        if(sum == k){
            return 1;
        }
        return 0;
    }

    sum = sum + arr[ind];
    int l = SubSeq(ind + 1, n, sum, k, arr);
    
    sum = sum - arr[ind];
    int r = SubSeq(ind + 1, n, sum, k, arr);

    return l + r;
}

int main(){
    int arr[] = {1,0,2,1};
    int n = 4;
    int k = 2;
    vector<int> vect;
    cout<<SubSeq(0, n, 0, k, arr)<<endl;

    return 0;
}