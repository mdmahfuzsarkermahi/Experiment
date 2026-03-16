#include <iostream>
using namespace std;

int main() 
{
    int arr[5];
    int *ptr = arr;
    int sum = 0;

    cout << "Enter Five Numbers : ";
    for(int i = 0; i < 5; i++) {
        cin >> *(ptr + i);
        sum += *(ptr + i);
    }
    cout << "Average : " << sum / 5.0;

    return 0;
}