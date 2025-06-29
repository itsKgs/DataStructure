#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
bool AnySubSeq(int ind, int n, int sum, int s, int arr[], vector<int>& vect){
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

    vect.push_back(arr[ind]);
    sum = sum + arr[ind];
    if(AnySubSeq(ind + 1, n, sum, s, arr, vect) == true){
        return true;
    }

    sum = sum - arr[ind];
    vect.pop_back();
    if(AnySubSeq(ind + 1, n, sum, s, arr, vect) == true){
        return true;
    }

    return false;
}

int main(){
    int arr[] = {1,4,3,2};
    int n = 4;
    int s = 5;
    vector<int> vect;
    AnySubSeq(0, n, 0, s, arr, vect);

    return 0;
}