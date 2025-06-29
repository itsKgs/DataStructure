#include <iostream>
using namespace std;

int main(){
    int n1,n2;
    cout<<"n1<<"<<endl;
    cin>>n1;
    cout<<"n2<<"<<endl;
    cin>>n2;
    char op;

    cout<<"Give opration"<<endl;
    cin>>op;
    
    switch (op)
    {
    case '+':
        cout<<n1+n2<<endl;
        break;
    case '-':
        cout<<n1-n2<<endl;
        break;
    case '*':
        cout<<n1*n2<<endl;
        break;
    case '/':
        cout<<n1/n2<<endl;
        break;
    
    default:
        cout<<"Enter another opration"<<endl;
        break;
    }

    return 0;
}