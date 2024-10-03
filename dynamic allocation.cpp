#include<iostream>
using namespace std;

class Array {
private:
    int* arr;      // Pointer to dynamically allocated array
    int size;      // Size of the array

public:
    // Constructor to allocate memory and initialize array
    Array(int s) {
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = i + 1;  // Initialize array with some values (1, 2, 3, ...)
        }
    }

    // Copy constructor for deep copy
    Array(const Array& other) {
        size = other.size;
        arr = new int[size]; // Allocate new memory
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i]; // Copy elements
        }
    }

    // Destructor to free allocated memory
    ~Array() {
        delete[] arr;
    }

    // Function to print array elements
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Array arr1(5);    // Create an array of size 5
    cout << "Original array (arr1): ";
    arr1.print();     // Print original array

    Array arr2 = arr1; // Create a deep copy of arr1
    cout << "Copied array (arr2): ";
    arr2.print();     // Print copied array

    return 0;
}

