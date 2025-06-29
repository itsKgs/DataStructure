#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> nums1{1,2,2,3,3,4,5,6};
    vector <int> nums2{2,3,3,5,6,6,7};

    vector <int> ans;
    int temp[nums2.size()] = {0};
    for (int i = 0; i < nums1.size(); i++){
        for (int j = 0; j < nums2.size(); j++){
            if (nums1[i] == nums2[j && temp[j] == 0]){
                ans.push_back(nums1[i]);
                temp[j]=1;
                break;
            } 
            if (nums2[j]>nums1[i]){
                break;
            }
        }
    }
    for (int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    
    
    

    return 0;
}