#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;
int fact(int n){
    if(n == 0) return 1;
    return n*fact(n-1);
}


int main(){
    vector<int> digits = {8,1,8};

    int n = digits.size();

    unordered_map<int, int> ev;
    unordered_map<int, int> odd;
    int ToatalEven = 0;
    int ToatalOdd = 0;
    for(int i = 0; i < n; i++){
        if(digits[i]%2 == 0){
            ev[digits[i]]++;
            ToatalEven++;
        }
        else{
            odd[digits[i]]++;
            ToatalOdd++;
        }
    }

    int distinctEven = ev.size();
    int distinctOdd = odd.size();
    cout<<distinctEven<<endl;
    cout<<distinctOdd<<endl;

    if(distinctEven == 0){
        cout<<"0"<<endl;
    }
    if(distinctEven == n){
        cout<<"1"<<endl;
    }
    cout<<distinctEven * fact(ToatalEven + ToatalOdd - 1)<<endl;

    return 0;
}