#include <iostream>
using namespace std;

int main()
{
    int k = 2;
    int arr[] = {3,12,33,1,100,4,50,5,160};
    int s_Element = arr[0];
    int k_smallest = arr[0];

    for (int i = 1; i < 9; i++)
    {
        if (s_Element >  arr[i] )
        {
            k_smallest = s_Element;
            s_Element = arr[i];
        }
        else if (s_Element < arr[i] && arr[i] < k_smallest )
        {
            k_smallest = arr[i];
        }
    }
    cout<<s_Element<<endl;
   
    cout<<k_smallest;
    return 0;
}