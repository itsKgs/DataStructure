#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main(){
    vector<int> nums = {1, 3, -1, -3, 5, 3, 2, 1, 6};
    int k = 3;

    deque < int > dq;
    vector < int > ans;
    for (int i = 0; i < nums.size(); i++) {
        if (!dq.empty() && dq.front() == i - k){
            dq.pop_front();
        }
        while (!dq.empty() && nums[dq.back()] < nums[i]){
          dq.pop_back();
        }
        
        dq.push_back(i);
        if (i >= k - 1){ 
            ans.push_back(nums[dq.front()]);
        }
    }

    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}