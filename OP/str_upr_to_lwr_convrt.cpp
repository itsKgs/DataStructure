#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s1 = "anhhdojhkbmzxkl";
    string s2 = "KHDKFHSDHFHIJLLGJG";
    string s3 = "jhsfkjhfhdfughflijli";
    string s4 = "JHKJHGKHGHWROIHTB";

    // Convert into Upper case
    for (int i = 0; i < s1.size(); i++){
        if (s1[i] >= 'a' && s1[i] <= 'z'){
            s1[i] = s1[i] - 32;
        }  
    }
    cout<<s1<<endl;

    // Convert into lower case
    for (int i = 0; i < s2.size(); i++){
        if (s2[i] >= 'A' && s2[i] <= 'Z'){
            s2[i] = s2[i] + 32;
        }  
    }
    cout<<s2<<endl;

    transform(s3.begin(), s3.end(), s3.begin(), :: toupper);
    cout<<s3<<endl;

    transform(s4.begin(), s4.end(), s4.begin(), :: tolower);
    cout<<s4<<endl;
    
    return 0;
}