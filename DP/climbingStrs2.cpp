#include<iostream>
#include<vector>
using namespace std;
// Memorization
int climbS(int ind, vector<int> &dp){
    if(ind <= 1){
        return 1;
    }
    if(dp[ind] != -1){
        return dp[ind];
    }
    return dp[ind] = climbS(ind - 1, dp) + climbS(ind - 2, dp);
}
int main(){
    int ind;
    cout<<"Enter index : ";
    cin>>ind;

    vector<int> dp(ind+1, -1);

    cout<<climbS(ind, dp)<<endl;
}