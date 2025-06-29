#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of character array: ";
    cin >> n;
    cin.ignore(); // To ignore the newline character after reading n

    char arr[n + 1];
    cout << "Enter the sentence: ";
    cin.getline(arr, n + 1);

    int i = 0;
    int curr_len = 0, max_len = 0;
    int start = 0, max_start = 0;

    while (true){
        if (arr[i] == ' ' || arr[i] == '\0') {
            if (curr_len > max_len){
                max_len = curr_len;
                max_start = start;
            }
            curr_len = 0;
            start = i + 1;
        } 
        else{
            curr_len++;
        }
        
        if (arr[i] == '\0'){
            break;
        }
        
        i++;
    }

    cout << "Length of the longest word: " << max_len << endl;
    cout << "Longest word: ";
    for (int i = 0; i < max_len; i++) {
        cout << arr[i + max_start];
    }
    cout << endl;

    return 0;
}
