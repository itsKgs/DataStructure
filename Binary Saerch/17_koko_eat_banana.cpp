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


    for(int i = 1; i <= mx; i++){
        int reqTime = reqT(piles, i);
        cout<<reqTime<<endl;
        if(reqTime <= h){
            cout<<i<<endl;
            break;
        }
    }

    return 0;
}