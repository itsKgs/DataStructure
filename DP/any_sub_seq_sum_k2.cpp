#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
//Memorization
bool AnySubSeq(int ind, int n, int sum, int s, int arr[], vector<int>& vect, vector<int>& dp){
    if(ind == n){
        if(sum == s){
            for(auto it : vect){
                cout<<it<<" ";
            }
            cout<<endl;
            return true;
        }
        else{
            return false;
        }
    }

    if(dp[ind] != -1){
        return dp[ind];
    }

    vect.push_back(arr[ind]);
    sum = sum + arr[ind];
    if(AnySubSeq(ind + 1, n, sum, s, arr, vect, dp) == true){
        return true;
    }

    sum = sum - arr[ind];
    vect.pop_back();
    if(AnySubSeq(ind + 1, n, sum, s, arr, vect, dp) == true){
        return true;
    }

    return false;
}

int main(){
    int arr[] = {6,1,2,1};
    int n = 4;
    int s = 4;
    vector<int> vect;
    vector<int> dp(n, -1);
    AnySubSeq(0, n, 0, s, arr, vect, dp);

    return 0;
}