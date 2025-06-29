#include <iostream>
#include <string.h>
using namespace std;

bool palindrome(int i, string &str){
    if(i >= (str.size()) / 2){
        return true;
    }
    if (str[i] != str[(str.size())-i-1]){
        return false;
    }
    return palindrome(i+1, str);
}

int main(){
    string str = "MADAM";
    cout<<palindrome(0, str);

    return 0;
}