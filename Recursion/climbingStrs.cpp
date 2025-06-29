#include<iostream>
using namespace std;
int climbS(int ind){
    if(ind == 0){
        return 1;
    }
    if(ind == 1){
        return 1;
    }
    int l = climbS(ind - 1);
    int r = climbS(ind - 2);
    return l+r;
}
int main(){
    int ind;
    cout<<"Enter index : ";
    cin>>ind;

    cout<<climbS(ind)<<endl;
}