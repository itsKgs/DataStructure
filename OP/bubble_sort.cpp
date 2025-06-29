#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the length of array ";
    cin>>n;

    int arr[n];
    for (int i = 0; i < n; i++){
        cout<<"Enter the "<<i<<"th element ";
        cin>>arr[i];
    }
    cout<<"array = ";
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
   //int counter=1;
   //while(counter < n){
   //    for (int j = 0; j < n-counter; j++){
   //        if (arr[j] > arr[j+1]){
   //            int temp = arr[j];
   //            arr[j] = arr[j+1];
   //            arr[j+1] = temp;
   //        }  
   //    }
   //    counter++;
   //}
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }  
        }
    }

    cout<<"sorted array = ";
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}