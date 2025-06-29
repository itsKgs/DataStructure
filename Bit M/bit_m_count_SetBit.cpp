#include <iostream>
using namespace std;

int CountSetBit_1(int n){
    int count = 0;
    while(n > 1){
        if (n%2 == 1){
            count++;
            n = n/2;
        } 
        else{
            n = n/2;
        }
    }
    if(n==1){
        count++;
    }
    return count;
}

int CountSetBit_2(int n){
    int count = 0;
    while (n != 0){
        count = count + (n & 1);
        n = n >> 1;
    }
    return count;
}

int CountSetBit_3(int n){
    int count = 0;
    while (n != 0){
        n = n & (n-1);
        count++;
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    cout<<CountSetBit_1(n)<<endl;
    cout<<CountSetBit_2(n)<<endl;
    cout<<CountSetBit_3(n)<<endl;
    return 0;
}
