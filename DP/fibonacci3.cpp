#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
//  Space Optimization
int main(){
    int n;
    cout<<"enter the num : ";
    cin>>n;

    int prev2 = 0;
    int prev = 1;
    for(int i = 2; i <= n; i++){
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    cout<<prev<<endl;

    return 0;
}
