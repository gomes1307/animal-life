#include <iostream>
#define PI 3.14159

using namespace std;

int main() {
  float radius;

  cout << "Enter the radius of the circle: ";
  cin >> radius;


  if (radius < 0) {
    cout << "Error: Radius cannot be negative." << endl;
    return 1;
  }

  float area = PI * radius * radius;

  cout << "Area of the circle: " << area << endl;

  return 0;
}

