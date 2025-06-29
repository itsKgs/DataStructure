#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> arr1{1,2,3,4,6};
    vector <int> arr2{2,3,5};

    int n1 = arr1.size();
    int n2 = arr2.size();

    int i=0;
    int j=0;
    vector <int> union_Arr;
    while (i < n1 && j < n2){
        if (arr1[i] <= arr2[j]){
            if(union_Arr.size() == 0 || union_Arr.back() != arr1[i]){
                union_Arr.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if(union_Arr.size() == 0 || union_Arr.back() != arr2[j]){
                union_Arr.push_back(arr2[j]);
            }
            j++;
        }  
    }

    while (j < n2){
        if(union_Arr.size() == 0 || union_Arr.back() != arr2[j]){
            union_Arr.push_back(arr2[j]);
        }
        j++;
    }
    
    while (i < n1){
        if(union_Arr.size() == 0 || union_Arr.back() != arr1[i]){
            union_Arr.push_back(arr1[i]);
        }
        i++; 
    }
    
    cout<<"union_Arr = ";
    for(int x : union_Arr){
        cout<< x <<" ";
    }

    return 0;
}