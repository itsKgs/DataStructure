#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;

int main(){
    int n, x, chs;
    float sum = 0;

    cout<<"1. e^(x)"<<endl;
    cout<<"2. sin(x)"<<endl;
    cout<<"3. cos(x)"<<endl;

    cout<<"Enter the choice "<<endl;
    cin>>chs;


    switch (chs){
        case 1:{
            int i = 0;
            cout<<"Enter the value of x ";
            cin>>x;
            cout<<"Enter the value of n ";
            cin>>n;

            while(i <= n){

                if(i==0){
                    sum = sum + 1;
                }
                else{
                    int fact = 1;
                    for(int j = 1; j<=i; j++){
                        fact = fact*j;
                    }
                    sum = sum + (pow(x,i))/fact;
                }
                i++;
            }
            cout<<"e^x = "<<sum<<endl;

            break;
        }
        case 2:{
            int i = 1;
            cout<<"Enter the value of x ";
            cin>>x;
            cout<<"Enter the value of n ";
            cin>>n;

            int temp = 0;
            while(i <= n){
                if(i%2 != 0){
                    int fact = 1;
                    for(int j = 1; j <= i; j++){
                        fact = fact*j;
                    }
                    if(temp%2 == 0){
                        sum = sum + (pow(x,i))/fact;
                    }
                    else{
                        sum = sum + (pow(-x,i))/fact;
                    } 
                }
                i++;
                temp++;
            }
            cout<<"Sin(x) = "<<sum<<endl;

            break;
        }
        case 3:{
            int i = 0;
            cout<<"Enter the value of x ";
            cin>>x;
            cout<<"Enter the value of n ";
            cin>>n;

            while(i <= n){

                if(i==0){
                    sum = sum + 1;
                }
                else{
                    if(i%2 == 0){
                        int fact = 1;
                        for(int j = 1; j <= i; j++){
                            fact = fact*j;
                        }
                        if(i%4 == 0){
                            sum = sum + (pow(x,i))/fact;
                        }
                        else{
                            sum = sum - (pow(x,i))/fact;
                        }
                    }
                }
                i++;
            }
            cout<<"Cos(x) = "<<sum<<endl;

            break;
        }
        default:
            cout<<"Enter the valid Choice"<<endl;
            break;
        }
    return 0;
    
}