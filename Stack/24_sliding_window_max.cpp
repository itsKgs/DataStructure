#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {1, 3, -1, -3, 5, 3, 2, 1, 6};
    nums.push_back(INT_MIN);
    int k = 3;
    int n = nums.size();
    vector<int> st;
    vector<int> ans;

    for(int i = 0; i < n; i++){//O(N)
        while(st.size() == k){//O(k)
            auto maxi = max_element(st.begin(), st.end());//O(K)
            cout<<*maxi<<endl;
            st.erase(st.begin());//O(K)
        }
        st.push_back(nums[i]);
    }

    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}