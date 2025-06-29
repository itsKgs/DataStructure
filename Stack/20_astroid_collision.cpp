#include <iostream>
#include <vector>
using namespace std;
//TC: O(N) + O(N) == O(2N)
//SC: O(N)
int main(){
    vector<int> arr = {4,7,1,1,2,-3,-7,17,15,-18,-19};
    int n = arr.size();
    vector<int> ans;

    for(int i = 0; i < n; i++){//O(N)
        if(arr[i] > 0){
            ans.push_back(arr[i]);
        }
        else{
            while(!ans.empty() && ans.back() > 0 && ans.back() < abs(arr[i])){//O(N)
                ans.pop_back();
            }

            if(!ans.empty() && abs(arr[i]) == ans.back()){
                ans.pop_back();
            }
            else if(ans.empty() || ans.back() < 0){
                ans.push_back(arr[i]);
            }
        }
    }

    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}