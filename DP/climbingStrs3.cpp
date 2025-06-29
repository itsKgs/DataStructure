#include<iostream>
#include<vector>
using namespace std;
// Tabulation
int main(){
    int ind;
    cout<<"Enter index : ";
    cin>>ind;

    if(ind <= 1){
        cout<<"1"<<endl;
        return 0;
    }

    vector<int> dp(ind+1, -1);
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= ind; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<dp[ind]<<endl;
    return 0;
}