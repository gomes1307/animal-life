#include <iostream>

using namespace std;

int main() {
  int arr[100];
  int n;

  cout << "Enter the size of the array (maximum 100): ";
  cin >> n;

  if (n <= 0 || n > 100) {
    cout << "Invalid array size." << endl;
    return 1;
  }

  cout << "Enter elements of the array:" << endl;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }


  int max = arr[0];
  int min = arr[0];


  for (int i = 1; i < n; ++i) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }


  for (int i = 1; i < n; ++i) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }

  cout << "Largest element in the array: " << max << endl;
  cout << "Smallest element in the array: " << min << endl;

  return 0;
}

