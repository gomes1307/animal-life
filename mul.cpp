#include <iostream>
#include <iomanip>
using namespace std;

#define ROW_MAX 12
#define COL_MAX 10

int main() {

  cout << endl;
  cout << "MULTIPLICATION TABLE" << endl << endl;

  for (int row = 1; row <= ROW_MAX; ++row) {
    for (int column = 1; column <= COL_MAX; ++column) {
      int y = row * column;
      cout << setw(4) << y;
    }
    cout << endl;
  }

  return 0;
}
