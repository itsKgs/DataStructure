#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void SubSeq(int ind, int n, int sum, int k, int arr[], vector <int> &vect ){
    if (ind >= n){
        //int sum = 0;
        //for(int i = 0; i < vect.size(); i++){
        //    sum = sum + vect[i];
        //}
        if(sum == k){
            for(auto x : vect){
                cout<<x<<" ";
            }
            cout<<endl;
        }
        return;
    }
    
    vect.push_back(arr[ind]);
    sum = sum + arr[ind];
    SubSeq(ind + 1, n, sum, k, arr, vect);
    
    sum = sum - arr[ind];
    vect.pop_back();
    SubSeq(ind + 1, n, sum, k, arr, vect);
}

int main(){
    int arr[] = {1,2,1};
    int n = 3;
    int k = 3;
    vector<int> vect;
    SubSeq(0, n, 0, k, arr, vect);

    return 0;
}