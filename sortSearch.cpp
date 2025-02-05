#include<iostream>
using namespace std;
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {

                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void findMinMax(int arr[], int n, int &min, int &max) {
    min = arr[0];
    max = arr[n-1];
}
int main() {
    int arr[10], n, i, min, max;
    cout << "Enter the number of elements (max 10): ";
    cin >> n;
    cout << "Enter the elements: ";
    for(i = 0; i < n; i++) {
        cin >> arr[i];
    }
    bubbleSort(arr, n);
    findMinMax(arr, n, min, max);

    cout << "Sorted array: ";
    for(i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Minimum element: " << min << endl;
    cout << "Maximum element: " << max << endl;

    return 0;
}
