#include <iostream>
#include <vector>
using namespace std;

// Memorization method
int fibonacci(int n, vector<int>&dp){
    if(n <= 1){
        return n;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = fibonacci(n-1, dp) + fibonacci(n-2, dp);
    return dp[n];
}

int main(){
    int n;
    cout<<"enter the num : ";
    cin>>n;

    vector<int> dp(n+1, -1);

    cout<<fibonacci(n, dp)<<endl;

    return 0;
}