#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int reqT(vector<int> &piles, double hourly){
    int n = piles.size();
    int totalT = 0;

    for(int i = 0; i < n; i++){
        totalT = totalT + ceil(double(piles[i])/hourly);
    }
    return totalT;
}

int main(){
    vector<int> piles = {3,6,7,11};
    int h = 8;
    int n = piles.size();
    int mx = *max_element(piles.begin(), piles.end());

    int low = 1;
    int high = mx;
    while(low <= high){
        int mid = low + (high - low)/2;
        int reqTime = reqT(piles, mid);
        if(reqTime <= h){
            cout<<mid<<endl;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return 0;
}