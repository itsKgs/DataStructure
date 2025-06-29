#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter number ";
    cin>>n;
    int num=n;
    int arm_num = 0;

    while (n!=0){
        int last_digit = n%10;
        arm_num = arm_num + (last_digit)*(last_digit)*(last_digit);
        n = n/10;
    }
    if (arm_num == num){
        cout<<"It's a Armstrong Number"<<endl;
    }
    else{
        cout<<"Not a Armstrong Number"<<endl;
    }

    return 0;
}