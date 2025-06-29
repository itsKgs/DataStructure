#include<iostream>
#include<vector>
using namespace std;
// Space Optimization
int main(){
    int ind;
    cout<<"Enter index : ";
    cin>>ind;

    if(ind <= 1){
        cout<<"1"<<endl;
        return 0;
    }

    int prev = 1;
    int prev2 = 1;


    for(int i = 2; i <= ind; i++){
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    cout<<prev<<endl;
    return 0;
}