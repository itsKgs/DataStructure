#include <iostream>
#include <set>
using namespace std;
//TC : O(N^2)
//Sc : O(3)
int main(){
    int arr[] = {3,3,3,1,2,1,1,2,3,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    int maxL = 0;
    for(int i = 0; i < n; i++){
        set<int> st;
        for(int j = i; j < n; j++){
            st.insert(arr[j]);
            if(st.size() <= 2){
                maxL = max(maxL, j - i + 1);
            }
            else{
                break;
            }
        }
    }
    cout<<maxL<<endl;

    return 0;
}
