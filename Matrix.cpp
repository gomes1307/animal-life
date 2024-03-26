#include <iostream>

using namespace std;

int main() {
  int rows1, cols1, rows2, cols2;


  cout << "Enter the dimensions of the first matrix (rows columns): ";
  cin >> rows1 >> cols1;

  cout << "Enter the dimensions of the second matrix (rows columns): ";
  cin >> rows2 >> cols2;


  if (cols1 != rows2) {
    cout << "Error: Matrix multiplication is not possible. Columns of first matrix must equal rows of second matrix." << endl;
    return 1;
  }


  int matrix1[rows1][cols1], matrix2[rows2][cols2], result[rows1][cols2];


  cout << "Enter elements for the first matrix:" << endl;
  for (int i = 0; i < rows1; ++i) {
    for (int j = 0; j < cols1; ++j) {
      cin >> matrix1[i][j];
    }
  }


  cout << "Enter elements for the second matrix:" << endl;
  for (int i = 0; i < rows2; ++i) {
    for (int j = 0; j < cols2; ++j) {
      cin >> matrix2[i][j];
    }
  }


  for (int i = 0; i < rows1; ++i) {
    for (int j = 0; j < cols2; ++j) {
      result[i][j] = 0;
      for (int k = 0; k < cols1; ++k) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }


  cout << "Resultant matrix:" << endl;
  for (int i = 0; i < rows1; ++i) {
    for (int j = 0; j < cols2; ++j) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}

