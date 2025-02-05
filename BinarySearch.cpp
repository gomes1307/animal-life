#include <iostream>
using namespace std;
int main() {
    int arr[10], i, low, high, mid, key, n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements in ascending order:"<<endl;
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the key to search: ";
    cin >> key;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key) {
            cout << "Key value " << key << " found at index " << mid << endl;
            return 0;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "Key value " << key << " not found in the array." << endl;
    return 0;
}
