#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& nums, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while(left <= mid && right <= high){
        if(nums[left] <= nums[right]){
            temp.push_back(nums[left]);
            left++;
        }
        else{
            temp.push_back(nums[right]);
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(nums[left]);
        left++;
    }

    while(right <= high){
        temp.push_back(nums[right]);
        right++;
    }

    for(int i = low; i <= high; i++){
        nums[i] = temp[i - low];
    }

}

void mergeSort(vector<int>& nums, int low, int high){
    if(low >= high){
        return;
    }

    int mid = (low + high)/2;

    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);
    merge(nums, low, mid, high);
}

int main(){
    vector<int> nums = {3, 1, 2, 4, 1, 5, 6, 2, 4};
    int n = nums.size();
    mergeSort(nums, 0, n - 1);

    for(int i = 0; i < n; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    return 0;
}