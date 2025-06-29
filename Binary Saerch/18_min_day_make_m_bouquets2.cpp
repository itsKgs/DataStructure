#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int findBqt(vector<int>& bloomDay, int k, int day){
    int n = bloomDay.size();

    int count = 0;
    int numBqt = 0;
    for(int i = 0; i < n; i++){
        if(bloomDay[i] <= day){
            count++;
        }
        else{
            numBqt = numBqt + count/k;
            count = 0;
        }
    }
    numBqt = numBqt + count/k;
    return numBqt;
}

int main(){
    vector<int> bloomDay = {7,7,7,7,12,7,7};
    int m = 2;
    int k = 3;

    int n = bloomDay.size();
    if(n < m*k){
        return -1;
    }
    auto minmax = minmax_element(bloomDay.begin(), bloomDay.end());
    int mn = *minmax.first;
    int mx = *minmax.second;
    int low = mn;
    int high = mx;

    while(low <= high){
        int mid = low + (high - low)/2;
        int numB = findBqt(bloomDay, k, mid);
        
        if(numB >= m){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    cout<<low<<endl;
    return 0;
}