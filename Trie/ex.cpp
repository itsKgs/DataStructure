#include <iostream>
using namespace std;

int main(){
    for(int i = 0; i < 10; i++){
        if(i >=0 ){
            if(i%2 == 0){
                cout<<"g"<<endl;
            }
            else{
                cout<<"a"<<endl;
                return false;
            }
        }
        else{
            return false;
        }
    }

    return 0;
}