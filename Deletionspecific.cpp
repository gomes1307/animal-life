#include <iostream>
using namespace std;
int main() {
    int arr[10], n, val;
    cout << "Enter a size: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter a value to remove: ";
    cin >> val;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
    }
    cout << "Modified array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
