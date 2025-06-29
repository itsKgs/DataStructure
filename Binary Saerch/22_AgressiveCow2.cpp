#include <iostream>
#include <vector>
#include <bits\stdc++.h>
using namespace std;
bool canWePlace(vector<int> &stalls, int k, int minD){
    int n = stalls.size();
    int countCow = 1;
    int last = stalls[0];
    for(int i = 1; i < n; i++){
        if(stalls[i] - last >= minD){
            last = stalls[i];
            countCow++;
        }
        if(countCow >= k){
            return true;
        }
    }
    return false;
}

int main(){
    vector<int> stalls{1, 2, 4, 8, 9};
    int k = 3;
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());

    int low = 1; 
    int high = stalls[n-1] - stalls[0];
    while(low <= high){
        int mid = low + (high - low)/2;
        if(canWePlace(stalls, k, mid) == true){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    cout<<high<<endl;

    return 0;
}