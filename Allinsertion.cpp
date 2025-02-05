#include <iostream>
using namespace std;
int main() {
    int c;
    cout << "Choose an insertion method:\n";
    cout << "1. Insert at a specific position\n";
    cout << "2. Insert at the end\n";
    cout << "3. Insert at the beginning\n";
    cin >> c;
    int arr[10];
    int size, val, pos;
    switch (c) {
        case 1:
            cout << "Enter the size of the array: ";
            cin >> size;
            cout << "Enter the array elements:\n";
            for (int i = 0; i < size; i++) {
                cin >> arr[i];
            }

            cout << "Enter the insertion position: ";
            cin >> pos;
            cout << "Enter the value to insert: ";
            cin >> val;
            for (int i = size - 1; i >= pos - 1; i--) {
                arr[i + 1] = arr[i];
            }

            arr[pos - 1] = val;
            size++;

            cout << "Array after insertion:\n";
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            break;

        case 2:
            cout << "Enter the size of the array: ";
            cin >> size;

            cout << "Enter the array elements:\n";
            for (int i = 0; i < size; i++) {
                cin >> arr[i];
            }

            cout << "Enter the value to insert: ";
            cin >> val;

            arr[size] = val;
            size++;

            cout << "Array after insertion:\n";
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            break;

        case 3:
            cout << "Enter the size of the array: ";
            cin >> size;

            cout << "Enter the array elements:\n";
            for (int i = 0; i < size; i++) {
                cin >> arr[i];
            }
            cout << "Enter the value to insert: ";
            cin >> val;
            for (int i = size ; i > 0; i--) {
                arr[i] = arr[i - 1];
            }
            arr[0] = val;
            size++;
            cout << "Array after insertion:\n";
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            break;
        default:
            cout << "Invalid choice.\n";
    }
    return 0;
}