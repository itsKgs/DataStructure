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
    int mn = stalls[0];
    int mx = stalls[n-1];
    
    
    for(int i = 1; i < mx - mn; i++){
        if(canWePlace(stalls, k, i) == true){
            continue;
        }
        else{
            cout<<i - 1<<endl;
            break;
        }
    }

    return 0;
}