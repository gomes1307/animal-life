#include <iostream>
using namespace std;

int main() {
  int arr1[] = {1, 3, 5};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);

  int arr2[] = {2, 4, 6};
  int n2 = sizeof(arr2) / sizeof(arr2[0]);

  int combinedSize = n1 + n2;
  int combinedArr[combinedSize];

  for (int i = 0; i < n1; ++i) {
    combinedArr[i] = arr1[i];
  }

  for (int i = 0; i < n2; ++i) {
    combinedArr[i + n1] = arr2[i];
  }

  cout << "Combined array: ";
  for (int i = 0; i < combinedSize; ++i) {
    cout << combinedArr[i] << " ";
  }
  cout << endl;

  return 0;
}
