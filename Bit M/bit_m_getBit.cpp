#include <iostream>
using namespace std;
int GetBit(int N, int pos){
    return (N & (1<<pos)) != 0;
}

int SetBit(int N, int pos){
    return (N | (1<<pos));
}

int ClearBit(int N, int pos){
    return (N & ~(1<<pos));
}

int ToggleBit(int N, int pos){
    return (N ^ (1<<pos));
}

int RemoveLastSetBit(int N){
    return (N & (N-1));
}

int main(){
    int N, pos;
    cin>>N>>pos;

    cout<<"GetBit "<<GetBit(N, pos)<<endl;
    cout<<"SetBit "<<SetBit(N, pos)<<endl;
    cout<<"ClearBit "<<ClearBit(N, pos)<<endl;
    cout<<"ToggleBit "<<ToggleBit(N, pos)<<endl;
    cout<<"RemoveLastSetBit "<<RemoveLastSetBit(N)<<endl;
    return 0;
}