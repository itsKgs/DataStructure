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

    for(int cap = mx; cap <= sum(weights); cap++){
        int reqD = reqDays(weights, cap);
        if(reqD <= days){
            cout<<cap<<endl;
            break;
        }
    }

    return 0;
}