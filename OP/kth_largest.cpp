#include <iostream>
using namespace std;

int main()
{
    int k = 2;
    int arr[] = {3,2,3,1,100,4,5,5,160};
    int Largest_Element = arr[0];
    int k_Largest = arr[0];

    for (int i = 1; i < 9; i++)
    {
        if (Largest_Element < arr[i] )
        {
            k_Largest = Largest_Element;
            Largest_Element = arr[i];
        }
        else if (Largest_Element > arr[i] && arr[i] > k_Largest )
        {
            k_Largest = arr[i];
        }
    }
    cout<<Largest_Element<<endl;
   
    cout<<k_Largest;
    return 0;
}


        