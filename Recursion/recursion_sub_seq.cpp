#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void SubSeq(int ind, int n, int arr[], vector <int> &vect ){
    if (ind == n){
        for(auto x : vect){
            cout<<x<<" ";
        }
        cout<<endl;
        return;
    }
    vect.push_back(arr[ind]);
    SubSeq(ind + 1, n, arr, vect);
    
    vect.pop_back();
    SubSeq(ind + 1, n, arr, vect);
}

int main(){
    int arr[] = {3,1,2};
    int n = 3;
    vector<int> vect;
    SubSeq(0, n, arr, vect);

    return 0;
}