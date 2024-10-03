#include <iostream>
#include <cstring> // For strcat

using namespace std;

int main() {
  char str1[100], str2[100];

  cout << "Enter the first string: ";
  cin.getline(str1, 100);

  cout << "Enter the second string: ";
  cin.getline(str2, 100);

  // Concatenate strings using strcat (caution: potential buffer overflow)
  strcat(str1, str2);

  cout << "Combined string: " << str1 << endl;

  return 0;
}
