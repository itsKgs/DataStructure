#include <iostream>
#include <vector>
using namespace std;
// Tabulation method
int main(){
    int n;
    cout<<"enter the num : ";
    cin>>n;
    
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout<<dp[n]<<endl;

    return 0;
}