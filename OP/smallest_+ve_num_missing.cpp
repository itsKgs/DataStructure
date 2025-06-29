#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter length = ";
    cin>>n;

    int nums[n];
    for (size_t i = 0; i < n; i++)
    {
        cout<<"Enter "<<i<<"th lement "<<endl;
        cin>>nums[i];
    }
    
    sort(nums, nums + n);
    int ans=1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i]==ans){
            ans++;
        }  
    }

    cout<<ans<<endl;
    return 0;
}
