#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int sum = 0;
    int j = 1;
    for(int i = 0; i < n; i++){
        if(j%7 == 0 && j%63 != 0){
            sum = sum + j;
        }
        else{
            i--;
        }
        j++;
    }
    cout<<sum<<endl;
    return 0;
}