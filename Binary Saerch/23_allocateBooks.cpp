#include <iostream>
#include <vector>
#include <bits\stdc++.h>
using namespace std;
int countStudent(vector<int> &arr, int pages){
    int student = 1;
    int pagesStudent = 0;
    int n = arr.size();
    
    for(int i = 0; i < n; i++){
        if(pagesStudent + arr[i] <= pages){
            pagesStudent += arr[i];
        }
        else{
            student++;
            pagesStudent = arr[i];
        }
    }
    return student;
}

int main(){
    vector<int> arr{15, 10, 19, 10, 5, 18, 7};
    int k = 5;  

    int n = arr.size();
    if(n < k){
        cout<<"-1"<<endl;
    }
    
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int countStd;
    
    for(int pages = low; pages <= high; pages++){
        countStd = countStudent(arr, pages);
        if(countStd <= k){
            cout<<pages<<endl;
            break;
        }
    }

    return 0;
}