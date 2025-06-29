#include <iostream>
#include <vector>
#include <bits/stdc++.h>
//// TC: O(2N) + O(2N) + O(N) == O(5N)
//SC: O(2N) + O(2N) + O(N) == O(5N)
using namespace std;
vector<int> findPGSE(vector<int>& nums){ // TC: O(2N), SC: O(2N)
    int n = nums.size();
    vector<int> left;
    stack<pair<int,int>> s;
    int psudo_index = -1;

    for(int i = 0; i < n; i++){
        if(s.size() == 0){
            left.push_back(psudo_index);
        }
        else if(s.size() > 0 && s.top().first >= nums[i]){
            left.push_back(s.top().second);
        }
        else if(s.size() > 0 && s.top().first < nums[i]){
            while (s.size() > 0 && s.top().first < nums[i]){
                s.pop();
            }
            if(s.size() == 0){
                left.push_back(psudo_index);
            }
            else{
                left.push_back(s.top().second);
            }
        }
        s.push({nums[i], i});
    }
    return left;
}

vector<int> findNGE(vector<int>& nums){// TC: O(2N), SC: O(2N)
    int n = nums.size();
    vector<int> right;
    stack<pair<int,int>> s;
    int psudo_index = n;

    for(int i = n - 1; i >= 0; i--){
        if(s.size() == 0){
            right.push_back(psudo_index);
        }
        else if(s.size() > 0 && s.top().first > nums[i]){
            right.push_back(s.top().second);
        }
        else if(s.size() > 0 && s.top().first <= nums[i]){
            while (s.size() > 0 && s.top().first <= nums[i]){
                s.pop();
            }
            if(s.size() == 0){
                right.push_back(psudo_index);
            }
            else{
                right.push_back(s.top().second);
            }
        }
        s.push({nums[i], i});
    }

    reverse(right.begin(), right.end());
    return right;
}

int main(){
    vector<int> nums = {19,19,62,66};
    int n = nums.size();

    vector<int> nse = findNGE(nums);
    vector<int> psse = findPGSE(nums);
    int total = 0;
    int mod = int(1e9 + 7);
    for(int i = 0; i < n; i++){ //O(N)
        int left = i - psse[i];
        int right = nse[i] - i;
        total = total + (left * right * nums[i]);
    }

    cout<<total<<endl;
    return 0;
}