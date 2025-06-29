#include <iostream>
#include <vector>
#include <bits\stdc++.h>
using namespace std;
int sum(vector<int>& weights){
    int n = weights.size();
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum = sum + weights[i];
    }
    return sum;
}

int reqDays(vector<int>& weights, int cap){
    int day = 1;
    int load = 0;
    int n = weights.size();

    for(int i = 0; i < n; i++){
        if(load + weights[i] > cap){
            day = day + 1;
            load = weights[i];
        }
        else{
            load = load + weights[i];
        }
    }
    return day;
}

int main(){
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    int n = weights.size();
    int mx = *max_element(weights.begin(), weights.end());
    int low = mx;
    int high = sum(weights);

    while(low <= high){
        int mid = low + (high - low)/2;
        int reqD = reqDays(weights, mid);
        if(reqD <= days){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    cout<<low<<endl;

    return 0;
}