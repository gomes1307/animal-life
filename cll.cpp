#include <iostream>

using namespace std;

int main() {
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int *ptr1 = arr1; // ptr1 points to the first element of arr1
    int *ptr2 = arr2; // ptr2 points to the first element of arr2

    cout << "Elements of arr1: ";
    for (int i = 0; i < size1; ++i) {
        cout << *(ptr1 + i) << " "; // Access elements using pointer arithmetic
    }
    cout << endl;

    cout << "Elements of arr2: ";
    for (int i = 0; i < size2; ++i) {
        cout << *(ptr2 + i) << " ";
    }
    cout << endl;

    // You can now process elements from both arrays using ptr1 and ptr2
    // (e.g., calculate sums, compare values, etc.)

    return 0;
}
