#include <iostream>

using namespace std;

int main() {
  int day;

  cout << "Enter a day number (1-7): ";
  cin >> day;

  switch (day) {
    case 1:
      cout << "Saturday" << endl;
      cout << "MATH 1203" << endl;
      cout << "CSE 1202" << endl;
      cout << "CSE 1201" << endl;
      cout << "GED 1201" << endl;
      break;
    case 2:
      cout << "Sunday" << endl;
      cout << "CSE 1206" << endl;
      cout << "PHY 1202" << endl;
      cout << "CSE 1201" << endl;
      break;
    case 4:
      cout << "Tuesday" << endl;
      cout << "MATH 1203" << endl;
      cout << "ENG 1205" << endl;
      cout << "CSE 1205" << endl;
      cout << "CSE 1205" << endl;
      break;
    case 5:
      cout << "Wednesday" << endl;
      cout << "PHY 1201" << endl;
      cout << "PHY 1201" << endl;
      cout << "ENG 1205" << endl;
      break;

    default:
      cout << "Holiday" << endl;
      break;
  }

  return 0;
}
